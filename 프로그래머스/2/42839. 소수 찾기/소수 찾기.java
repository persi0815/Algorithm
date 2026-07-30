import java.util.*; 

// 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 
class Solution {
    
    HashSet<Integer> set = new HashSet<>(); 
    boolean[] visited;
    int answer = 0;
    
    boolean[] notPrime = new boolean[10000000]; 
    public boolean isPrime(int num){
        if(notPrime[num]) return false; 
        else return true; 
    }
    
    public int solution(String numbers) {
        char[] nums = numbers.toCharArray();
        
        Integer[] intNums = new Integer[nums.length]; 
        for(int i = 0; i < nums.length; i++) {
            char c = nums[i];
            intNums[i] = Integer.parseInt(String.valueOf(c)); 
        }
        
        notPrime[0] = true; notPrime[1] = true; 
        for(int i = 2; i < Math.sqrt(10000000); i++){
            for(int j = i*i; j < 10000000; j+=i){
                notPrime[j] = true; 
            }
        }
        
        visited = new boolean[intNums.length]; 
        
        recursive(0, 0, intNums);
        
        return answer;
    }
    
    public void recursive(int len, int cur, Integer[] intNums){
        if(len > 0 && !set.contains(cur)){
            if(isPrime(cur)) answer++; 
            set.add(cur); 
        }
        // 다음꺼
        for(int i = 0; i < intNums.length; i++){
            if(visited[i]) continue; 
            
            visited[i] = true; 
            recursive(len+1, cur * 10 + intNums[i], intNums); 
            visited[i] = false; 
        }
        
    }
    
}