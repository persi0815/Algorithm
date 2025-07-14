import java.util.*;

class Solution {
    /*
    완탐하면 시간초과
    
    */
    
    public boolean solution(String[] phone_book) {
        boolean answer = true; // 접두어인게 있다면 false, 없다면 true
        
        Arrays.sort(phone_book); // 문자열 기준 오름차순 정렬
        
        for(int i = 0; i < phone_book.length - 1; i++){
            if(phone_book[i+1].startsWith(phone_book[i])){
                answer = false; break;
            }
        }
        
        
        return answer;
    }
}