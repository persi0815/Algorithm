import java.util.*;

class Solution {
    
    // k개 골라 상자에 담아 판매. 상자에 서로 다른 종류의 수를 최소화
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        
        // {크기, 개수}
        HashMap<Integer, Integer> nums = new HashMap<>();
        for(int t : tangerine){
            nums.put(t, nums.getOrDefault(t, 0)+1);
        }
        List<Integer> sizes = new ArrayList<>(nums.values());
        sizes.sort((a, b) -> {
            return Integer.compare(b, a);
        }); 
        
        // 가장 크기가 큰 것부터 개수 세기
        int kLeft = k; 
        for(int siz : sizes){
            answer++;
            kLeft -= siz; 
            if(kLeft <= 0) break;
        }
        
        
        // 귤 k개를 고를 때 크기가 서로 다른 종류의 수의 최솟값을 return
        return answer;
    }
}