import java.util.*;

class Solution {
    
    
    public boolean solution(int n, int[][] path, int[][] order) {
        // 연결리스트 만들기
        List<Integer>[] graph = new ArrayList[n]; 
        for(int i = 0; i < n; i++) graph[i] = new ArrayList<>(); 
        for(int[] p : path){
            graph[p[0]].add(p[1]); 
            graph[p[1]].add(p[0]); 
        }
        
        // order에서 뒷순위 set 만들기
        HashSet<Integer> nextNodes = new HashSet<>(); // 아직 앞순위가 안나온 뒷순위들
        int[] orders = new int[n];
        Arrays.fill(orders, -1);
        for(int[] o : order){
            nextNodes.add(o[1]); 
            orders[o[0]] = o[1]; 
        }
        
        // 0부터 bfs돌면서 뒷순위set 확인후 갈 수 있으면 가기. while문 돌고 나서 못 간 곳 있으면 안됨. 
        Queue<Integer> q = new LinkedList<>(); 
        boolean[] visited = new boolean[n]; // 탐험한 곳들
        HashSet<Integer> waiting = new HashSet<>(); // 앞순위가 안나와서 탐험하기 불가능한 곳들
        
        q.offer(0); visited[0] = true; 
        if(nextNodes.contains(0)) return false; // 0이 뒷순위라면 불가능.
        if(orders[0] != -1) nextNodes.remove(orders[0]); // 앞순위가 0인거 해제시켜주기.
        while(!q.isEmpty()){ // v+e = 400,000
            int cur = q.poll(); 
                
            for(int nxt : graph[cur]){
                // 이미 다룬 적이 있음
                if(visited[nxt]) continue;  
                // set에 아직 있으면(prev 아직 안나옴) 건너뛰기
                if(nextNodes.contains(nxt)){
                    waiting.add(nxt); 
                }
                // set에 없으면 방문
                else{ 
                    visited[nxt] = true; 
                    q.offer(nxt);
                    
                    int nextNode = orders[nxt];
                    if(nextNode != -1){
                        nextNodes.remove(nextNode); // 이젠 탐험 가능하다 선포
                        if(waiting.contains(nextNode)){ // 앞순위 안나와서 그 아래들 탐험 못한거니까 q 넣어주기
                            waiting.remove(nextNode); 
                            visited[nextNode] = true; 
                            q.offer(nextNode);
                        }
                    }
                }
            }
        }
        
        // 모든 방 탐색했다면? 
        boolean answer = true;
        for(int i = 0; i < n; i++){
            if(!visited[i]) answer = false;
        }
            
        // 프로도가 규칙에 맞게 모든 방을 탐험할 수 있을 지 return
        return answer;
    }
}