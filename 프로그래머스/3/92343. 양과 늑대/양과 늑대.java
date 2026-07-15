import java.util.*; 


class Solution {
    int maxSheep;
    int[] info;
    List<Integer>[] graph; // 연결 그래프(부모-자식)
    
        
    public int solution(int[] info, int[][] edges) { // edges: [부모 노드 번호, 자식 노드 번호]
        this.info = info;
        this.maxSheep = 0;
        
        // 연결 그래프 만들기
        graph = new ArrayList[info.length];
        for(int i = 0; i < info.length; i++) graph[i] = new ArrayList<>(); 
        for(int[] e : edges){
            int parent = e[0]; int child = e[1]; 
            graph[parent].add(child); 
        }
        
        // 각 상황에 존재하는 양과 늑대 수
        List<Integer>[] animals = new ArrayList[2]; // 양, 늑대 수
        for(int i = 0; i < 2; i++) animals[i] = new ArrayList<>(); 
        animals[0].add(0); // 첫 양의 위치 삽입
        
        // 백트래킹으로 검색 시작
        gatherAnimals(0, 0, animals);

        // 모을 수 있는 양은 최대 몇 마리인지
        return maxSheep;
    }
    
    public void gatherAnimals(int sheepNum, int wolfNum, List<Integer>[] animals){ // 양, 늑대 누적 수 
        
        // 양이 있다면 다 데려오기(답 갱신) -> 그의 자식들 전부 배열에 넣어주기
        while(!animals[0].isEmpty()){
            int sheepNode = animals[0].remove(animals[0].size() - 1); // 제거하며 반환
            sheepNum++;
            addChildren(sheepNode, animals); // 자식 추가

            maxSheep = Math.max(maxSheep, sheepNum);
        }

        // 늑대 데려갈 수 없다면 return 
        if(sheepNum <= wolfNum + 1) return;

        // 양이 없다면 늑대 한 마리씩 차례대로 돌아가면서 데려가기
        for (int i = 0; i < animals[1].size(); i++) {
            int wolfNode = animals[1].get(i); // 늑대 한 마리 선택

            List<Integer>[] nextAnimals = copyAnimals(animals); // 얕은 복사!!
            nextAnimals[1].remove(i); // 이번 늑대는 방문했으니 제거
            addChildren(wolfNode, nextAnimals); // 자식 추가
            gatherAnimals(sheepNum, wolfNum+1, nextAnimals); // 재귀 (새로 만든 배열 전달해서 이전의 데이터는 유지되도록)
        }
            
    }

    // 자식을 배열에 추가해주기 (양/늑대 구분)
    private void addChildren(int node,List<Integer>[] animals) {
        for (int child : graph[node]) {
            if (info[child] == 0) {
                animals[0].add(child);
            } else {
                animals[1].add(child);
            }
        }
    }
    
    // 안의 내용까지 얕은 복사
    private List<Integer>[] copyAnimals(List<Integer>[] animals) {
        List<Integer>[] copied = new ArrayList[2];

        copied[0] = new ArrayList<>(animals[0]);
        copied[1] = new ArrayList<>(animals[1]);

        return copied;
    }
}