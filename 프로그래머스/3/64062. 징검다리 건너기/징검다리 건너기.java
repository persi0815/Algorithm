import java.util.*;

class Solution {
    
    
    public int solution(int[] stones, int k) {
        int answer = 0;
        
        // 이분탐색으로 명수 구하기
        int left = 1; int right = 200000000;
        while(left <= right){
            int mid = (left + right)/2; 
            
            int seq = 0; boolean avail = true;
            for(int s : stones){
                if(s < mid) {
                    seq++;
                    if(seq +1 > k){
                        avail = false; break;
                    }
                }
                else seq = 0;
            }
            if(!avail) right = mid-1; 
            else {
                answer = mid;
                left = mid +1;
            }
        }
        
        // 최대 몇 명까지 징검다리를 건널 수 있는지 return
        return answer;
    }
}