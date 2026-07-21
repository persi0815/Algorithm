import java.util.*; 


class Solution {
    
    List<Integer>[] graph; 
    
    public int solution(int n, int[][] wires) {
        int answer = Integer.MAX_VALUE;
        
        // 연결리스트 만들기
        graph = new ArrayList[n+1]; 
        for(int i = 0; i < n+1; i++) graph[i] = new ArrayList<>(); 
        for(int[] w : wires){
            graph[w[0]].add(w[1]); 
            graph[w[1]].add(w[0]); 
        }
        
        // 노드 두개 붙잡고 연결되어 있나 확인 후 하나 끊기
        for(int i = 1; i <= n-1; i++){
            for(int j = i+1; j <= n; j++){
                if(graph[i].contains(j)){
                    answer = Math.min(answer, Math.abs(bfs(i, j) - bfs(j, i))); 
                }   
            }
        }
        
        
        //  전선들 중 하나를 끊어서 송전탑 개수가 가능한 비슷하도록 두 전력망으로 나누었을 때, 
        // 두 전력망이 가지고 있는 송전탑 개수의 차이(절대값)를 return
        return answer;
    }
    
    // 해당 트리의 노드 개수 반환
    public int bfs(int start, int except){
        int num = 0; 
        boolean[] visited = new boolean[101]; 
        Queue<Integer> q = new LinkedList<>(); 
        
        q.offer(start); visited[start] = true; num++; 
        while(!q.isEmpty()){
            int cur = q.poll(); 
            
            for(int nxt : graph[cur]){
                if(visited[nxt]) continue;
                if(nxt == except) continue; 
                
                q.offer(nxt); 
                visited[nxt] = true; 
                num++;
            }
        }
        
        return num;
    }
    
}