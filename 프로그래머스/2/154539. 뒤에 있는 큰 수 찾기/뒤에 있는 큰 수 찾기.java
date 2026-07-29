import java.util.*;


class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length]; 
        Arrays.fill(answer, -1);
        
        Stack<Integer> stack = new Stack<>(); stack.add(0); 
        for(int i = 1; i < numbers.length; i++){
            int num = numbers[i]; 
            while(!stack.isEmpty()){
                if(numbers[stack.peek()] < num){
                    answer[stack.peek()] = num; 
                    stack.pop(); 
                }else{
                    break;
                }
            }
            stack.add(i);
        }
        
        
        
        // 배열 의 각 원소들에 대해 자신보다 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수를 뒷 큰수
        // 모든 원소에 대한 뒷 큰수들을 차례로 담은 배열을 return
        return answer;
    }
}