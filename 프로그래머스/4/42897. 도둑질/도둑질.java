import java.util.*; 

class Solution {
    
    public int solution(int[] money) {
        int siz = money.length;
        int[] firstO = new int[siz]; firstO[0] = money[0]; firstO[1] = Math.max(firstO[0], money[1]);
        int[] firstX = new int[siz]; firstX[1] = money[1]; firstX[2] = Math.max(firstX[1], money[2]);
        
        for(int i = 2; i < siz-1; i++){
            firstO[i] = Math.max(
                firstO[i-1], 
                firstO[i-2] + money[i]
            );
        }
        for(int i = 3; i < siz; i++){
            firstX[i] += Math.max(
                firstX[i-1], 
                firstX[i-2] + money[i]
            );
        }
        
        
        return Math.max(firstO[siz-2], firstX[siz-1]);
    }
}