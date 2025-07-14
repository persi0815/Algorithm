import java.util.*;
/*
괄호가 짝지어져 있지 않다면 false. 짝지어져 있다면 true

짝 여부를 stack으로. (괄호를 )가 없앨 수 있음. 마지막에 괄호 있다면 false.
*/

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        Stack<Character> stack = new Stack<>();
        
        if(s.charAt(0) != '(') answer = false;
        else{
            stack.push(s.charAt(0));
            for(int i = 1; i < s.length(); i++){
                if(!stack.isEmpty()){
                    char top = stack.peek();
                    if(top == '(' && s.charAt(i) != top) stack.pop();
                    else stack.push(s.charAt(i));
                } 
                else{
                    stack.push(s.charAt(i));
                }

            }
        }
        
        if(answer == true) answer = stack.isEmpty() ? true : false;
        return answer;
    }
}