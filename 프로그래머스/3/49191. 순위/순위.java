import java.util.*; 

class Solution {
    boolean[] visited;
    
    public int solution(int n, int[][] results) {
        int answer = 0;
        
        // 자신을 이긴 선수들
        Set<Integer>[] win = new HashSet[n+1];
        for(int i = 0; i <= n; i++){
            win[i] = new HashSet<>(); 
        }
        
        // 자신에게 진 선수들
        Set<Integer>[] lose = new HashSet[n+1];
        for(int i = 0; i <= n; i++){
            lose[i] = new HashSet<>(); 
        }
        
        for(int[] r : results){
            int w = r[0]; int l = r[1];
            win[l].add(w);
            lose[w].add(l);
        }
        
        visited = new boolean[n+1]; 
        
        for(int i = 1; i <= n; i++){ // 100
            bfs(win, i); // 4600
            bfs(lose, i);
        }
        
        
        // 자신을 이긴 선수 + 자신에게 진 선수 = n-1이면 순위 매길 수 있는 것
        for(int i = 1; i <= n; i++){
            if(win[i].size() + lose[i].size() == n-1) answer++;
        }
        
        // 정확하게 순위를 매길 수 있는 선수의 수
        return answer;
    }
    
    void bfs(Set<Integer>[] graph, int i){
        Arrays.fill(visited, false);
        Queue<Integer> q = new LinkedList<>(); 
        q.offer(i); visited[i] = true;
        while(!q.isEmpty()){
            int m = q.poll(); 

            for(int p : graph[m]){
                if(visited[p]) continue;
                visited[p] = true; 
                q.offer(p);
                graph[i].add(p);
            }
        }
    }
}