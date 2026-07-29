import java.util.*; 

class Solution {
    boolean[] visited;
    List<Integer>[] graph;
    
    public int solution(int n, int[][] computers) {
        
        visited = new boolean[n]; 
        
        // 연결리스트 만들기
        graph = new ArrayList[n]; 
        for(int i = 0; i < n; i++) graph[i] = new ArrayList<>(); 
        for(int i = 0; i < n; i++){
            for(int j = i+1; j< n; j++){
                if(computers[i][j] == 1){
                    graph[i].add(j); 
                    graph[j].add(i); 
                }
            }
        }
        
        // 네트워크 개수 세기
        int answer = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            bfs(i); answer++;
        }
        
        // 네트워크의 개수를 return 
        return answer;
    }
    
    public void bfs(int start){
        Queue<Integer> q = new ArrayDeque<>(); 
        q.offer(start); visited[start] = true; 
        while(!q.isEmpty()){
            int cur = q.poll(); 
            
            for(int nxt : graph[cur]){
                if(visited[nxt]) continue; 
                visited[nxt] = true;
                q.offer(nxt); 
            }
        }
        
    }
}