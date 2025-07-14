import java.util.*;

class Solution {
    // 최대한 다양한 종류의 포켓몬을 가지길 원함. 
    // 최대한 많은 종류의 포켓몬을 포함해서 n/2 마리를 선택하려고 함. 
    
    // n 마리 포켓몬의 종류 번호가 담김
    public int solution(int[] nums) {
        int answer = 0; // 가장 많은 종류의 포켓몬을 선택하는 방법의 종류 번호의 개수는
        
        // 각 포켓몬 종류의 개수를 파악. {종류, 개수}
        Map<Integer, Integer> typeNum = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            typeNum.put(nums[i], typeNum.getOrDefault(nums[i], 0) + 1);
        }
        
        // key 개수가 n/2 보다 같거나 작은 것 중 가장 큰 값 도출
        int types = typeNum.size(); 
        int poketmons = nums.length;

        answer = types > poketmons/2 ? poketmons/2 : types;
        
        
        return answer;
    }
}