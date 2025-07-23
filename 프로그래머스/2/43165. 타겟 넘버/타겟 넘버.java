import java.util.*;

class Solution {
    int answer = 0; // 개수
    
    public void find(int now, int sum, int target, int[] numbers){
        if(sum == target) {
            answer++;
            //System.out.println("find: "+ now + " " + sum);
            return;
        } else if(sum < target) return;
        
        for(int i = now+1; i < numbers.length; i++){
            //System.out.println(i + " " + (sum-(2*numbers[i])));
            find(i, sum-2*numbers[i], target, numbers);
        }
        
    }
    
    public int solution(int[] numbers, int target) {
        
        // 오름차순 정렬
        Arrays.sort(numbers);
        int sum = 0; 
        for(int n: numbers) sum += n;
        
        // 마이너스인 것을 조합으로 구해나가기
        find(-1, sum, target, numbers);

        return answer;
    }
}