import java.util.*; 

class Node{
    int num; int cost; 
    public Node(int num, int cost){
        this.num = num; 
        this.cost = cost; 
    }
}

class Solution {
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        // 각 지점까지의 최소 intensity
        int[] min_intensity = new int[n+1]; 
        Arrays.fill(min_intensity, Integer.MAX_VALUE); 
        
        // set 만들기
        HashSet<Integer> gateSet = new HashSet<>(); 
        for(int g : gates)  gateSet.add(g); 
        HashSet<Integer> summitSet = new HashSet<>(); 
        for(int s : summits) summitSet.add(s); 
        
        // 연결리스트 만들기 -  next, cost
        List<Node>[] graph = new ArrayList[n+1]; 
        for(int i = 0; i < n+1; i++) graph[i] = new ArrayList<>(); 
        for(int[] p : paths){
            int i = p[0]; int j = p[1]; int w = p[2]; 
            graph[i].add(new Node(j, w)); 
            graph[j].add(new Node(i, w)); // 양방향
        }
            
        // 다익스트라로 각 지점까지의 최소 intensity 구하기
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> {
            return a.cost - b.cost; // 오름차순
        }); 
        for(int g : gates) {
            pq.offer(new Node(g, 0)); 
            min_intensity[g] = 0; 
        }
        while(!pq.isEmpty()){
            Node cur = pq.peek(); pq.poll(); 
            
            // 고려할 필요 없다고 판단되면 제거!!
            if(cur.cost > min_intensity[cur.num]) continue;
            
            for(Node nxt : graph[cur.num]){
                // 출발지점이라면 continue
                if(gateSet.contains(nxt.num)) continue;
                
                // 이미 nxt의 min_intensity가 더 작은 경우 continue
                int new_intensity = Math.max(cur.cost, nxt.cost);
                if(min_intensity[nxt.num] <= new_intensity) continue; 
                
                // 갱신(쉼터, 산봉오리)
                min_intensity[nxt.num] = new_intensity; 
                
                // 쉼터라면 pq 넣기
                if(!summitSet.contains(nxt.num)){
                    pq.offer(new Node(nxt.num, new_intensity)); 
                }
            }
            
        }
         
        // 산봉오리들 중에서 최소 intensity 가진 산들 중 산봉우리의 번호가 가장 작은거 구하기
        int[][] res = new int[summits.length][2];
        for(int s = 0; s < summits.length; s++){
            int v = summits[s]; 
            res[s][0] = v; 
            res[s][1] = min_intensity[v];
        }
        // 정렬
        Arrays.sort(res, (a, b)-> {
            if(a[1] != b[1]) return a[1] - b[1]; 
            else return a[0] - b[0]; 
        }); 
        
        return new int[]{res[0][0], res[0][1]}; // [산봉우리의 번호, intensity의 최솟값]
    }
}