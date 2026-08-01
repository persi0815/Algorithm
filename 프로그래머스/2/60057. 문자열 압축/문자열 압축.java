import java.util.*; 

// 1개 이상 단위로 문자열을 잘라 압축하여 표현한 문자열 중 가장 짧은 것의 길이 리턴
class Solution {
    
    public int solution(String str) {
        int answer = str.length();
        
        for(int len = 1; len <= str.length()/2; len++){
            int ans = 0;
            String bef = ""; boolean avail = false; int num = 1;
            
            for(int s = 0; s <= str.length() - len; s+=len){
                if(bef.equals(str.substring(s, s+len))){
                    avail = true; num++;
                }else{
                    if(avail) {
                        ans += String.valueOf(num).length();
                        avail = false; 
                    }
                    num = 1; // 초기화
                    bef = str.substring(s, s+len);
                    ans += len; 
                }
            }
            if(avail) ans += String.valueOf(num).length();
            
            ans += str.length() % len;  // 나머지
            
            answer = Math.min(answer, ans);
        }
        
        return answer;
    }
}