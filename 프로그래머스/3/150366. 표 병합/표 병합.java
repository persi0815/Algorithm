import java.util.*; 

class Solution {
    int[] parent = new int[2551]; // [자식] = 부모 노드
    String[] data = new String[2551]; // (부모)노드의 데이터

    public int toIdx(int r, int c){
        return r*50+c;
    }
    public int[] toYX(int idx){
        return new int[]{idx/50, idx%50};
    }
    
    // 부모 찾기
    public int find(int idx){
        if(parent[idx] == idx) return idx; 
        return parent[idx] = find(parent[idx]); // 압축
    }
    
    
    
    public String[] solution(String[] commands) {
        List<String> answer = new ArrayList<>();
        
        // 값 저장 배열
        Arrays.fill(data, "EMPTY"); // 빈 값으로 초기화
        
        // 부모 노드 저장 배열
        for(int i = 0; i <= 2550; i++){
            parent[i] = i; // 자기 자신으로 초기화
        }
        
        // 명령어 하나씩 돌아가면서 처리
        for(String s : commands){ // 1,000
            String[] order = s.split(" "); 
            String o = order[0];
            if(o.equals("UPDATE")){
                // "UPDATE r c value" -> r c 위치의 셀을 value로 변환
                if(order.length == 4){
                    int r = Integer.parseInt(order[1]); int c = Integer.parseInt(order[2]); 
                    String value = order[3];
                    int[] par = toYX(find(toIdx(r, c))); 
                    data[toIdx(par[0], par[1])] = value;
                    
                }
                // "UPDATE value1 value2" -> value1가지던 셀들을 모두 value2로 변환
                else{
                    String value1 = order[1]; String value2 = order[2];
                    for(int i = 0; i <=2500; i++){
                        if(data[parent[i]].equals(value1)) data[parent[i]] = value2;
                    }
                }
            }
            
            // "MERGE r1 c1 r2 c2" -> 둘중에 하나만 값이 있다면 그걸로, 모두 있다면 r1 c1꺼로 병합
            else if(o.equals("MERGE")){
                int r1 = Integer.parseInt(order[1]); int c1 = Integer.parseInt(order[2]); 
                int r2 = Integer.parseInt(order[3]); int c2 = Integer.parseInt(order[4]);
                int par1 = find(toIdx(r1, c1));
                int par2 = find(toIdx(r2, c2));
                // 같은 셀인 경우 무시
                if(par1 == par2) continue;
                // 다른 셀이라면 병합
                if(!data[par1].equals("EMPTY") && !data[par2].equals("EMPTY")){
                    parent[par2] = par1;
                }else if(!data[par1].equals("EMPTY")){
                    parent[par2] = par1;
                }else if(!data[par2].equals("EMPTY")){
                    parent[par1] = par2;
                }else{
                    parent[par2] = par1;
                }                
            }
            
            // "UNMERGE r c" -> r,c가 포함되었던 셀의 값을 r,c가 갖고 나머지 셀들은 모두 빈 각자만의 칸으로 돌아감
            else if(o.equals("UNMERGE")){
                int r = Integer.parseInt(order[1]); int c = Integer.parseInt(order[2]);
                int par = find(toIdx(r, c)); 
                String d = data[par];
                for(int i = 0; i <= 2550 ; i++){
                    if(find(i) == par){ 
                        parent[i] = par; // 중간 부모 없게 처리
                    }
                }
                for(int i = 0; i <= 2550 ; i++){
                    if(parent[i] == par){ // 같은 부모를 갖는
                        parent[i] = i; 
                        data[i] = "EMPTY"; // 나머지들은 빈 각자만의 칸으로 돌아감
                    }
                }
                data[toIdx(r, c)] = d; // r c가 값을 가짐
            }
            
            // "PRINT r c" -> 출력
            else if(o.equals("PRINT")){
                int r = Integer.parseInt(order[1]); int c = Integer.parseInt(order[2]);
                answer.add(data[find(toIdx(r, c))]);
            }
        }
        
        return answer.stream().toArray(String[]::new); // toArray
    }
}