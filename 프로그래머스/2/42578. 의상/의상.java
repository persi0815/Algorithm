import java.util.*; 

class Solution {
    public int solution(String[][] clothes) {
        
        HashMap<String, Integer> variable = new HashMap<>(); 
        for(String[] c : clothes){
            variable.put(c[1], variable.getOrDefault(c[1], 0) + 1); 
        }
        
        int answer = 1;
        List<Integer> nums = new ArrayList<>(variable.values()); 
        for(int i = 0; i < nums.size(); i++){
            answer *= (nums.get(i) + 1);
        }
        
        // 서로 다른 옷의 조합의 수
        return answer - 1;
    }
}