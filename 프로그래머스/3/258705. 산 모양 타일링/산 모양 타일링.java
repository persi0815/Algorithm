import java.util.*;

class Solution {
    
    public int solution(int n, int[] tops) {
        int answer = 0;
        
        // 해당 상황의 가짓수 저장하는 배열
        int[][] dp = new int[4][n]; 
        
        // 연산
        List<Integer>[][] cal = new ArrayList[4][4];
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cal[i][j] = new ArrayList<>(); 
            }
        }
        // 1 1
        cal[0][1] = new ArrayList<>(Arrays.asList(1, 2, 3)); 
        cal[0][2] = new ArrayList<>(Arrays.asList(1, 2, 3)); 
        cal[0][3] = new ArrayList<>(Arrays.asList(1, 3)); 
        // 1 0
        cal[1][1] = new ArrayList<>(Arrays.asList(2, 3)); 
        cal[1][2] = new ArrayList<>(Arrays.asList(2, 3)); 
        cal[1][3] = new ArrayList<>(Arrays.asList(3)); 
        // 0 1
        cal[2][2] = new ArrayList<>(Arrays.asList(1, 2, 3)); 
        cal[2][3] = new ArrayList<>(Arrays.asList(1, 3)); 
        // 0 0
        cal[3][2] = new ArrayList<>(Arrays.asList(2, 3)); 
        cal[3][3] = new ArrayList<>(Arrays.asList(3)); 
        
        // 초기화
        for (int state = 0; state < 4; state++) {
            dp[state][0] = 1;
        }
        if (tops[0] == 0) dp[1][0] = 0;
        // 한 차례씩 dp 시작
        for(int i = 1; i < n; i++){
            // 0을 모두에게
            for (int state = 0; state < 4; state++) dp[state][i] = dp[0][i - 1];
            if(tops[i] == 0) dp[1][i] = 0; // 불가능하니까
            // 상태 1, 2, 3 모두 처리
            for(int j = 1; j <= 3; j++) 
                dp[0][i] = (dp[0][i] + dp[j][i-1]) % 10007;
            // 나머지 연산할 상황 구하기
            int cid;
            if(tops[i-1] == 1){
                cid = (tops[i] == 1) ? 0 : 1; 
            }else{
                cid = (tops[i] == 1) ? 2 : 3; 
            }
            // 연산
            for (int before = 1; before < 4; before++) {
                int count = dp[before][i - 1];

                for (int to : cal[cid][before]) {
                    dp[to][i] = (dp[to][i] + count) % 10007;
                }
            }
            // 결과 출력
            // System.out.println(dp[0][i] + " "+ dp[1][i] + " " +dp[2][i] + " " +dp[3][i] );
        }
        
        // 정삼각형 또는 마름모 타일로 빈 곳이 없도록 채우는 경우의 수를 10007로 나눈 나머지를 return
        return (dp[0][n-1] + dp[1][n-1] + dp[2][n-1] + dp[3][n-1]) % 10007;
    }
}