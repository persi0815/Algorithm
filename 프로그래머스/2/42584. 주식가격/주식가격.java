import java.util.*; 
/*
스택으로 항상 작은 값이 아래에 깔려. 
시간은 인덱스로 계산!
새로 들어오는 값보다 큰건 전부 빼. 그리고 해당 값 넣어. 
*/

class Solution {
    public int[] solution(int[] prices) {
        int num = prices.length;
        int[] answer = new int[num];
        Stack<Integer> stack = new Stack<>(); 
        
        stack.push(0);
        for(int i = 1; i < num; i++){
            if(!stack.isEmpty()){
                while(true){
                    if(stack.isEmpty()) break;
                    
                    int peek = stack.peek(); 
                    if(prices[peek] > prices[i]){ // 현재 값보다 들어가있는게 크면 pop
                        stack.pop(); 
                        answer[peek] = i - peek;
                    }
                    else break; // 더 이상 prices에 들어있는 것 중에 더 큰게 없으면 break;
                }
                stack.push(i);
            
            }else{
                stack.push(i);
            }
        }
        
        int siz = stack.size();
        for(int i = 0; i < siz; i++){
            int peek = stack.pop(); 
            answer[peek] = num - peek - 1;
        }
        
        
        return answer;
    }
}