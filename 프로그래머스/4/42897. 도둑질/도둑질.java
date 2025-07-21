import java.util.*; 
/*
dp[선택 유무][i까지] = 최댓값
*/

class Solution {
    
    // 집에 있는 돈
    public int solution(int[] money) {
        int cnt = money.length;
        
        int[][] dp = new int[2][cnt];
        int[][] dp_n = new int[2][cnt];
        
        Arrays.fill(dp[0], 0); // 0, 2 
        Arrays.fill(dp[1], 0); // 1
        
        dp[1][0] = money[0]; dp[1][1] = money[1]; dp[1][2] = dp[1][0] + money[2];
        dp[0][0] = 0; dp[0][1] = dp[1][0]; dp[0][2] = dp[1][1]; 
        
        dp_n[1][0] = 0; dp_n[1][1] = money[1]; dp_n[1][2] = money[2];
        dp_n[0][0] = 0; dp_n[0][1] = 0; dp_n[0][2] = money[1];
        
        if (cnt == 3) {
            return Math.max(
                Math.max(dp_n[1][2], dp_n[0][2]),
                Math.max(dp[1][1], dp[0][2])
            );
        }

        for(int i = 3; i < cnt; i++){
            if(i == cnt-1){ // 마지막이면 1번째꺼 털었었으면 마지막꺼 털면 안됨. 
                dp[0][i] = Math.max(dp[1][i-1], dp[1][i-2]); 
            }
            else{
                dp[1][i] = Math.max(dp[1][i-2], dp[1][i-3]) + money[i];
                dp[1][i] = Math.max(dp[0][i-1] + money[i], dp[1][i]);
                
                dp[0][i] = Math.max(dp[1][i-1], dp[1][i-2]);
                dp[0][i] = Math.max(dp[0][i], dp[0][i-1]);
            }
            
            dp_n[1][i] = Math.max(dp_n[1][i-2], dp_n[1][i-3]) + money[i];
            dp_n[1][i] = Math.max(dp_n[0][i-1] + money[i], dp_n[1][i]);

            dp_n[0][i] = Math.max(dp_n[1][i-1], dp_n[1][i-2]);
            dp_n[0][i] = Math.max(dp_n[0][i], dp_n[0][i-1]);
        }
        
        return Math.max(
                Math.max(dp_n[0][cnt-1], dp_n[1][cnt-1]),
                dp[0][cnt-1]
            );

    }
}