import java.util.*;

class Solution {
    
    private static final String DIGITS = "0123456789ABCDEF";
    
    // 10진수 from => n진수 string으로 변환
    public String toN(int n, int from){
        StringBuilder ans = new StringBuilder();
        if(from == 0) return "0"; 
        while(from > 0){
            ans.append(DIGITS.charAt(from % n)); 
            from /= n;
        }
        // 거꾸로
        return ans.reverse().toString();
    }
 
                                        
    // 진법, 구할 숫자 갯수, 참가 인원, 순서
    public String solution(int n, int t, int m, int p) {
        int cur = 0; 
        
        StringBuilder numbers = new StringBuilder(); 
        // String으로 모든 수 기록 -> t*m 길이가 될 때까지
        while(numbers.length() < t*m){
            // 10진수 -> N진법으로 변환
            numbers.append(toN(n, cur)); 
            cur++;
        }
        
        // 말해야 하는 숫자 구하기
        StringBuilder answer = new StringBuilder();
        for(int i = p-1; i < t*m; i+=m){
            answer.append(numbers.charAt(i));
        }

        // 말해야 하는 숫자 출력
        return answer.toString();
    }
}