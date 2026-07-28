import java.util.*; 

class Solution {
    public int solution(int[] arr) {
        int answer = 1;
        boolean[] finish = new boolean[arr.length]; 
        int fin = 0; 
        // 하나씩 1로 만들기
        for(int n = 2; n < 100; n++){
            boolean avail = false; 
            for(int i = 0; i < arr.length; i++){
                if(finish[i]) continue; 
                if(arr[i] % n == 0){
                    avail = true; 
                    arr[i] /= n; 
                    if(arr[i] == 1) {
                        finish[i] = true; fin++;
                    }
                }
            }
            if(avail) {
                answer *= n; 
                n--; // 다시
            }
            if(fin == arr.length) break; 
        }
        
        // n개의 숫자를 담은 배열 arr이 입력되었을 때 이 수들의 최소공배수
        return answer;
    }
}