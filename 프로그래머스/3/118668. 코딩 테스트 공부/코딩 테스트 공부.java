import java.util.*;

class Skill{
    int alp; int cop; int c;
    public Skill(int alp, int cop){
        this.alp = alp; this.cop = cop; 
    }
}
class Solution {
    public int solution(int curAlp, int curCop, int[][] problems) {
        
        // 도달해야 하는 alp, cop 구하기
        int targetAlp = 0; int targetCop = 0; 
        for(int[] p : problems){ //  [alp_req, cop_req, alp_rwd, cop_rwd, cost]
            int alp_req = p[0]; int cop_req = p[1]; 
            targetAlp = Math.max(targetAlp, alp_req); 
            targetCop = Math.max(targetCop, cop_req);
        }
        
        // 줄이고 시작. target으로 리턴할꺼니까
        curAlp = Math.min(curAlp, targetAlp);
        curCop = Math.min(curCop, targetCop);
        
        // dp[a][c] = min cost : a,c에 도달할 때까지 걸린 최소 비용
        int dp[][] = new int[301][301];
        for(int[] list : dp) Arrays.fill(list, Integer.MAX_VALUE);
        dp[curAlp][curCop] = 0;
        // dp 갱신
        for(int a = curAlp; a <= targetAlp; a++){ // 150
            for(int c = curCop; c <= targetCop; c++){ // 150
                if (dp[a][c] == Integer.MAX_VALUE) continue;
                
                // 공부로 올리기
                if (c < targetCop) dp[a][c+1] = Math.min(dp[a][c+1], dp[a][c]+1);
                if (a < targetAlp) dp[a+1][c] = Math.min(dp[a+1][c], dp[a][c]+1);
                
                // 문제로 올리기
                for(int[] p : problems){ // 100
                    int alp_req = p[0]; int cop_req = p[1]; 
                    int alp_rwd = p[2]; int cop_rwd = p[3]; 
                    int cost = p[4];
                    // 현재 상태가 req를 넘는지 확인
                    if(a < alp_req || c < cop_req) continue; 
                    // 갱신
                    int nxtAlp = Math.min(targetAlp, a + alp_rwd);
                    int nxtCop = Math.min(targetCop, c + cop_rwd);
                    dp[nxtAlp][nxtCop] = Math.min(dp[nxtAlp][nxtCop], dp[a][c] + cost);
                    
                }
                
               
            }
        }
        
      
        // 모든 문제들을 풀 수 있는 알고력과 코딩력을 얻는 최단시간을 return
        return dp[targetAlp][targetCop];
    }
}