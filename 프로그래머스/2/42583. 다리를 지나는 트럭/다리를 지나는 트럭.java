import java.util.*; 
/*
여러 대가 강을 가로지를 때 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아야 함. 
다리에는 최대 bridge_length대까지 올라갈 수 있음. 다리는 weight 이하까지의 무게를 견딜 수 있음. 

현재 다리를 건너고 있는 트럭들을 투 포인터로 관리, 무게 관리 -> 다음 트럭 지날 수 있는지 판단
*/

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int truckNum = truck_weights.length;
        int time = 0; // 모든 트럭이 다리를 건너는데 걸리는 시간
        
        // 초기화
        int next_idx = 0; // 다음에 지나갈 트럭 인덱스
        int load = 0;
        Queue<Integer> bridge = new LinkedList<>(); 
        for(int i = 0; i < bridge_length; i++){
            bridge.add(0); 
        }
        
        // 트럭 이동시키기
        while(next_idx < truckNum){
            
            int next_truck = truck_weights[next_idx];
            if(next_truck + load - bridge.peek() <= weight){ // 올릴 수 있다면
                load = load + next_truck - bridge.peek();
                bridge.poll(); 
                bridge.add(next_truck);
                next_idx++;
            }else{ // 올릴 수 없음
                load = load - bridge.peek();
                bridge.poll(); 
                bridge.add(0);
            }
            
            time++;
            
        }
        
        
        return time + bridge_length;
    }
}