import java.util.*; 

class Solution {
    
    Deque<Character> stack = new ArrayDeque<>(); 
    
    public int solution(String s) {
        int answer = 0; 
        
        StringBuilder sb = new StringBuilder(); 
        sb.append(s);
        if(isAvail(sb)) answer++; 
        // 회전 시키고 확인하고 반복 - 1,000,000
        for(int i = 0; i < s.length() -1; i++){
            char first = sb.charAt(0); 
            sb.append(first); 
            sb.delete(0, 1); 
            if(isAvail(sb)) answer++; 
        }
        
        // s를 왼쪽으로 x만큼 회전시켰을때 x가 올바른 괄호 문자열이 되게하는 x의 개수를 리턴
        return answer;
    }
    
    public boolean isAvail(StringBuilder sb){
        stack.clear(); 
        for(int i = 0; i < sb.length(); i++){
            char cur = sb.charAt(i); 
            // 제거
            if(!stack.isEmpty()){
                if(cur == ')' && stack.peek() == '(') stack.pop();
                else if(cur == '}' && stack.peek() == '{') stack.pop();
                else if (cur == ']' && stack.peek() == '[') stack.pop();
                else stack.push(cur); 
            }
            // 담기
            else stack.push(cur); 
        }
        if(stack.isEmpty()) return true; 
        else return false; 
    }
}