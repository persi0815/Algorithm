import java.util.*;

// 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는가
class Solution {
    
    class Truck{
        int weight; int approach; 
        public Truck(int weight, int approach){
            this.weight = weight; this.approach = approach; 
        }
    }
    
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        
        // 정해진 순서대로 다리 건너기
        Queue<Truck> q = new ArrayDeque<>(); 
        int total_weight = 0; // 다리에 있는 트럭 총 무게 
        int cur_time = 1;  // 현재 시각
        
        for(int t = 0; t < truck_weights.length; t++){ 
            int truck = truck_weights[t]; // 해당 트럭 다리에 실을 것
            
            // 시간 지난거 내리기
            if(!q.isEmpty() && (q.peek().approach == (cur_time - bridge_length))) {
                Truck bef = q.poll();
                total_weight -= bef.weight;  // 물건 내리기
            }
            
            // 무게가 한계에 도달했다면 -> 시간 흘려보내면서 트럭들 내리기
            while(!q.isEmpty() && weight < (total_weight + truck)){
                // 아직 내릴 시간이 안됨
                if(q.peek().approach > (cur_time - bridge_length)){
                    cur_time = q.peek().approach + bridge_length; // 내릴 수 있는 시간으로 만들어버리기
                }
                // 내릴 시간이 됨.
                Truck bef = q.poll(); 
                total_weight -= bef.weight;  // 물건 내리기
            }
            
            // 해당 차 큐에 넣기
            q.offer(new Truck(truck, cur_time)); 
            total_weight += truck;
            answer = cur_time + bridge_length;
            
            
            // 다음 시간으로
            cur_time++;
        }
        
        // 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 return
        return answer;
    }
}