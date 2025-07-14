import java.util.*;

public class Solution {
    // 배열 arr 0~9에서 연속적으로 나타나는 수 하나만 남기고 전부 제거. 다만, 순서 유지해야 함
    public int[] solution(int []arr) {
        int[] answer = {};
        
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < arr.length; i++){
            if(stack.isEmpty()) stack.push(arr[i]); 
            else{
                int top = stack.peek(); 
                if(arr[i] != top) stack.push(arr[i]);
            }
        }
        
        List<Integer> nums = new ArrayList<>(); 
        
        for(int i = 0; i < stack.size(); i++){
            nums.add(stack.get(i));
        }
        
        return answer = nums.stream().mapToInt(i -> i).toArray();
    }
}