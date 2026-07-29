import java.util.*; 

class Solution {
    
    public int[] solution(int n, int s) {
        
        
        // 존재하지 않으면 [-1] 리턴
        if(s/n < 1) return new int[]{-1}; 
        
        // n개를 골라서 합이 s, 곱이 최대
        int[] ans = new int[n];
        for(int i = 0; i < n; i++) ans[i] = (s/n); // 10,000 
        
        // 나머지로 매꿔주기
        int id = n-1; 
        for(int k = s%n; k > 0; k--){ // 100,000,000
            ans[id]++;
            id--;
        }
        
        return ans;
    }
}