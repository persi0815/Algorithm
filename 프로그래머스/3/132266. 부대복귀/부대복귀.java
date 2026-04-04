import java.util.*;
class Node{
    int now; int cost; 
    Node(int now, int cost){
        this.now = now; 
        this.cost = cost;
    }
}
class Solution {
    int[] min_cost; // min_cost[노드] = 노드로의 최단 거리
    int INT_MAX = Integer.MAX_VALUE;
    
    public void bfs(List<Integer>[] graph, int s){ // v+e = 200,000        
        Queue<Node> q = new LinkedList<>(); 
        q.offer(new Node(s, 0)); 
        min_cost[s] = 0; 
        while(!q.isEmpty()){
            Node node = q.poll(); 
            int now = node.now; int cost = node.cost; 
            
            for(int next : graph[now]){
                if(min_cost[next] != -1 && min_cost[next] <= cost + 1) continue; 
                min_cost[next] = cost + 1;
                q.offer(new Node(next, cost+1));
            }
        }
    }
    
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        List<Integer> answer = new ArrayList<>();
        min_cost = new int[n+1];
        Arrays.fill(min_cost, -1);
        
        // 연결리스트 만들기
        List<Integer>[] graph = new ArrayList[n+1]; 
        for(int i = 0; i <= n; i++){
            graph[i] = new ArrayList<>(); 
        }
        for(int[] r : roads){
            int a = r[0]; int b = r[1];
            graph[a].add(b); graph[b].add(a); 
        }
        
        // bfs로 각 부대원으로의 최단 거리 구하기
        bfs(graph, destination); // 200,000 
        
        for(int s : sources){
            answer.add(min_cost[s]);
        }

        // sources의 원소 순서대로 강철부대로 복귀할 수 있는 최단시간을 담은 배열. 불가능 할 경우 -1
        return answer.stream().mapToInt(i->i).toArray(); 
    }
}