import java.util.*; 

// 남은 병사의 수보다 현재 라운드의 적의 수가 더 많으면 게임이 종료
// 게임에는 무적권이라는 스킬이 있으며, 무적권을 사용하면 병사의 소모없이 한 라운드의 공격을 막을 수 있음 -> k번
class Solution {
    
    // 무적권을 적절한 시기에 사용하여 최대한 많은 라운드를 진행하고자 -> 적이 많을 때 사용. 
    public int solution(int n, int k, int[] enemy) {
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            return Integer.compare(b, a); // maxheap
        });
        
        for(int round = 0; round < enemy.length; round++){ // 1,000,000
            int e = enemy[round]; 
            
            // n 감축
            n -= e; 
            pq.offer(e);
            
            // n이 양수가 될때까지 무적권 사용
            while(!pq.isEmpty() && k > 0 && n < 0){
                n += pq.poll(); 
                k--;
            }
            
            // 더 이상 무적권 사용 못함
            if(n < 0){ 
                return round;
            }
        }
        
        // 준호가 몇 라운드까지 막을 수 있는지
        return enemy.length; // 다 막음
    }
}