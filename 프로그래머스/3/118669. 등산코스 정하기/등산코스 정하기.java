import java.util.*;

class Corse{
    int summit; int intensity; 
    Corse(int summit, int intensity){
        this.summit = summit; 
        this.intensity = intensity; 
    }
}
class Path{
    int next; int intensity;
    Path(int next, int intensity){
        this.next = next; 
        this.intensity = intensity;
    }
}
class Node{
    int to; int cost; 
    Node(int to, int cost){
        this.to = to; 
        this.cost = cost;
    }
}
class Solution {
    int INT_MAX = Integer.MAX_VALUE; 
    Set<Integer> summit_set = new HashSet<>(); // 산봉우리 유무 판단 시 사용
    Set<Integer> gate_set = new HashSet<>(); // 출발지 유무 판단 시 사용
    List<Corse> corses = new ArrayList<>(); // 가능한 경로들
    int[] min_intensity;
    
    public void findPath(List<Node>[] graph, int[] gates){
        PriorityQueue<Path> q = new PriorityQueue<>((a, b) -> { // 어짜피 짧은 것만 살아남으니
            return a.intensity - b.intensity;
        }); 
        Arrays.fill(min_intensity, INT_MAX);
        
        for(int g : gates){ // 초기값
            q.offer(new Path(g, 0));
            min_intensity[g] = 0;
        }
        
        while(!q.isEmpty()){
            Path path = q.poll();
            int next = path.next; int intensity = path.intensity;
            if(min_intensity[next] < intensity) continue; // 더 작은게 나왔었다면 pass
            
            for(Node n : graph[next]){
                // 출발지점인지 확인
                if(gate_set.contains(n.to)) continue; 
                // 해당 지점까지의 min_intensity보다 크면 컨티뉴
                if(min_intensity[n.to] <= Math.max(intensity, n.cost)) continue; 
                
                min_intensity[n.to] = Math.max(intensity, n.cost);
                // 산봉우린지 확인
                if(summit_set.contains(n.to)){
                    // corses.add(new Corse(n.to, Math.max(intensity, n.cost)));
                    continue;
                }
                q.offer(new Path(n.to, Math.max(intensity, n.cost)));
            }
        }
        
    }
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        // 유무 확인에 사용할 set 만들기
        for(int s : summits){
            summit_set.add(s);
        }
        for(int g : gates){
            gate_set.add(g);
        }
        min_intensity = new int[n+1];
        
        // 연결리스트
        List<Node>[] graph = new ArrayList[n+1];
        for(int i = 0; i <= n; i++){
            graph[i] = new ArrayList<>(); 
        }
        for(int[] p : paths){
            int i = p[0]; int j = p[1]; int w = p[2];
            graph[i].add(new Node(j, w)); 
            graph[j].add(new Node(i, w)); 
        }
        
        // 출발지에서 산봉우리까지의 path를 구해야 함
        findPath(graph, gates);
        
        
        // intensity가 가장 작은 경로 구하기. 여러 개면 선봉우리 번호가 가장 낮은 코스
        int res_summit = INT_MAX; int res_intensity = INT_MAX;
        for(int i = 1; i <= n; i++){
            if(summit_set.contains(i)) {
                if(res_intensity > min_intensity[i]){
                    res_summit = i; res_intensity = min_intensity[i];
                }else if(res_intensity == min_intensity[i] && res_summit > i){
                    res_summit = i; res_intensity = min_intensity[i];
                }
            }
        }
        // corses.sort((a, b) -> {
        //     if(a.intensity != b.intensity) return a.intensity - b.intensity; 
        //     else return a.summit - b.summit;
        // });
        
        // return new int[]{corses.get(0).summit, corses.get(0).intensity};
        return new int[]{res_summit, res_intensity};
        // intensity가 최소가 되는 등산코스에 포함된 산봉우리 번호, intensity의 최솟값
    }
}