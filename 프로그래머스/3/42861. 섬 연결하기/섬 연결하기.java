import java.util.*; 

// 최소의 비용으로 모든 섬이 서로 통행 가능하도록
class Solution {
    
    class Node{
        int to; int cost; 
        public Node(int to, int cost){
            this.to = to; this.cost = cost; 
        }
    }
    
    List<Node>[] graph; 
    
    // 비용이 작은 것부터 선택
    PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> {
        return Integer.compare(a.cost, b.cost); 
    });
    
    // 최소 간선 비용 반환
    public int prim(int n){ // 현재 트리에서 이을 수 있는 간선 중 가장 비용이 작은 것. 
        boolean[] visited = new boolean[n];
        pq.offer(new Node(0, 0)); 
        int totalCost = 0; 
        
        while(!pq.isEmpty()){
            Node cur = pq.poll(); 
            
            if(visited[cur.to]) continue; // 방문 안했어야 -> 사이클 안생김
            visited[cur.to] = true; 
            totalCost += cur.cost; // 가장 작은 간선으로 이동!
            
            for(Node nxt : graph[cur.to]){ // 연결된 간선들 모두
                if(visited[nxt.to]) continue; // 아직 연결되지 않은 것들 중에
                pq.offer(nxt);
            }
        }
        
        return totalCost;
    }
    
    public int solution(int n, int[][] costs) {
        // 연결리스트 만들기
        graph = new ArrayList[n];
        for(int i = 0; i < n; i++) graph[i] = new ArrayList<>(); 
        for(int[] c : costs){
            graph[c[0]].add(new Node(c[1], c[2]));
            graph[c[1]].add(new Node(c[0], c[2]));
        }
        
        // pq에서 하나씩 고르기 -> 사이클 없는지 확인
        while(!pq.isEmpty()){
            Node node = pq.poll(); 
            
        }
        
        return prim(n);
    }
    
    
    
}