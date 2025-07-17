import java.util.*;
/*
0또는 양의 정수 -> 정수를 이어 붙여 만들 수 있는 가장 큰 수?
수 내림차순 정렬인데, 문자열로 내림차순 해야 할 듯
*/

class Solution {
    public String solution(int[] numbers) {
        
        List<String> nums = new ArrayList<>(); 
        for(int i = 0; i < numbers.length; i++){
            nums.add(String.valueOf(numbers[i]));
        }
        
        // "3" < "30" 인 문제 해결
        Collections.sort(nums, (a, b) -> (b + a).compareTo(a + b));
        
        // 가장 앞 숫자가 "0"이면 전체가 0
        if (nums.get(0).equals("0")) return "0";
        
        StringBuilder answer = new StringBuilder();
        for (String s : nums) {
            answer.append(s);
        }
        
        return answer.toString();
    }
}