import java.util.*;

class Solution {
    public int solution(String word) {
        int answer = 0;
        
        Character[] alpha = new Character[]{'A', 'E', 'I', 'O', 'U'}; 
        int[] num = new int[]{ 781 ,156 ,31, 6, 1};
        
        for(int i = 0; i < word.length(); i++){
            for(int a = 0; a < 5; a++){
                if(word.charAt(i) == (alpha[a])){
                    answer+=(a*num[i]);
                    break;
                }    
            }
            answer+=1;
        }
        
        // 단어 하나 word가 매개변수로 주어질 때, 이 단어가 사전에서 몇 번째 단어인지 return 
        return answer;
    }
}