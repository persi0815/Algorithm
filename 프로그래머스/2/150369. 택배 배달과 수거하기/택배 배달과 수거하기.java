import java.util.*;

class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
            
        int del = n-1; // 배달이 남은 가장 먼 집
        int pic = n-1; // 픽업이 남은 가장 먼집
        
        // 가장 먼 집부터 배달, 픽업
        while(true){ // 10만 * 100 = 1억
            // 배달 첫 집
            while(del >= 0 && deliveries[del] == 0) del--;
            // 픽업 첫 집
            while(pic >= 0 && pickups[pic] == 0) pic--;
            
            // 둘다 -1이 되어 끝났다면 끝내기
            if(del < 0 && pic < 0) break;
                        
            // 이동거리 갱신
            answer += (Math.max((del < 0) ? -1 : del, (pic < 0) ? -1 : pic) + 1) * 2;    
            
            // 배달, 수거 가능 크기 확보
            int dc = cap; int pc = cap; 
            // 배달
            while(dc > 0 && del >= 0){ // 50 - 공간도 있고 할 것도 남아있어
                if(deliveries[del] > 0){
                    dc--; deliveries[del]--; 
                }
                if(deliveries[del] <= 0){
                    del--; 
                }
            }
            // 수거
            while(pc > 0 && pic >= 0){ // 50 - 공간도 있고 할 것도 남아있어
                if(pickups[pic] > 0){ 
                    pc--; pickups[pic]--; 
                }
                if(pickups[pic] <= 0) {
                    pic--; // 여기서 pic가 음수가 될 수 있음
                }
            }
            // 물류창고로 가기
        }
        
        return answer;
    }
}