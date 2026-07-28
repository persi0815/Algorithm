import java.util.*; 

class Solution {
    public long solution(int n) {
        long[] cnt = new long[n+1]; 
        cnt[1] = 1; 
        if(n >= 2) cnt[2] = 2; 
        for(int i = 3; i <= n; i++){
            cnt[i] = (cnt[i-1] + cnt[i-2]) % 1234567; 
        }
        
        // 효진이가 끝에 도달하는 방법의 가짓수
        long answer = cnt[n];
        return answer;
    }
}