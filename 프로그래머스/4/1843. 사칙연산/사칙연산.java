import java.util.*; 

class Solution {
    public int solution(String arr[]) {
        
        // - 뒤에는 가장 작은 수, + 뒤에는 가장 큰 수
        // 순차적으로 dp 계산이 불가능함. => 구간 별 최대 최소 저장
        int n = (arr.length + 1)/2;
        int[][] maxDp = new int[n][n]; // dp[시작][끝]
        int[][] minDp = new int[n][n]; 
        
        // 기호랑 수랑 분리
        List<Integer> nums = new ArrayList<>(); 
        List<Character> orders = new ArrayList<>(); 
        for(int i = 0; i < arr.length; i++){
            if(i%2 == 0) nums.add(Integer.parseInt(arr[i])); 
            else orders.add(arr[i].charAt(0)); 
        }
        
        // 기반 만들기
        for(int i = 0; i < n; i++) {
            Arrays.fill(minDp[i], Integer.MAX_VALUE);
            Arrays.fill(maxDp[i], Integer.MIN_VALUE);
        }
        for(int i = 0; i <= n-1; i++){
            maxDp[i][i] = nums.get(i);
            minDp[i][i] = nums.get(i);
        }
        
        // 작은 범위부터 큰 범위까지 각각의 최소, 최대 값 계산
        for(int len = 2; len <= n; len++){ // 길이 (작은 것부터)
            for(int i = 0; i <= n-len; i++){ // 시작
                int j = i+len-1; // 끝
                
                for(int k = i; k < j; k++){ // 연산 위치
                    if(orders.get(k) == '+'){
                        maxDp[i][j] = Math.max(maxDp[i][j], maxDp[i][k] + maxDp[k+1][j]); 
                        minDp[i][j] = Math.min(minDp[i][j], minDp[i][k] + minDp[k+1][j]); 
                        
                    }else{ // '-'
                        maxDp[i][j] = Math.max(maxDp[i][j], maxDp[i][k] - minDp[k+1][j]); 
                        minDp[i][j] = Math.min(minDp[i][j], minDp[i][k] - maxDp[k+1][j]); 
                        
                    }
                }
            }
        }

        
        // 서로 다른 연산순서의 계산 결과 중 최댓값
        int answer = maxDp[0][n-1];
        return answer;
    }
}