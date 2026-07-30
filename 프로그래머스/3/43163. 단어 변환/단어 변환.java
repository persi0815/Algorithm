import java.util.*; 

class Solution {

    
    // 무엇을 몇번만에 갔는지
    
    public int solution(String begin, String target, String[] words) {
        
        Queue<String> q = new ArrayDeque<>(); 
        
        HashMap<String, Integer> visited = new HashMap<>(); 
        
        q.offer(begin); visited.put(begin, 0); 
        while(!q.isEmpty()){
            String cur = q.poll();
            if(cur.equals(target)) return visited.get(cur); 
            
            for(String nxt : words){
                // 방문하지 않았던거 
                if(visited.containsKey(nxt)) continue; 
                // 한개만 차이는거
                int diff = calculateDiff(cur, nxt); 
                if(diff != 1) continue; 
                // 갱신
                q.offer(nxt); 
                visited.put(nxt, visited.get(cur)+1);
            }
        }
        
        // 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return
        return 0; // 불가능한 경우 0 리턴
    }
                   
    public int calculateDiff(String a, String b){ // 모든 단어의 길이는 같습니다.
        // 단어의 길이는 3 이상 10 이하
        int len = a.length(); 
        int diff = 0; 
        for(int i = 0; i < len; i++){
            if(a.charAt(i) != b.charAt(i)) diff++;
        }
        return diff; 
    }
    
    
}