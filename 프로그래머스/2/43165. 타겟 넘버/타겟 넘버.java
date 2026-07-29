import java.util.*; 

class Solution {
    int answer = 0;
    
    public int solution(int[] numbers, int target) {
        
        // 백트래킹 가능(완탐)
        backtraking(1, numbers[0], numbers.length, target, numbers);
        backtraking(1, -numbers[0], numbers.length, target, numbers);
        
        // 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수
        return answer;
    }
    
    public void backtraking(int id, int res, int siz, int target, int[] numbers){
        if(id == siz){
            if(res == target) answer++;
            return;
        }
        backtraking(id+1, res - numbers[id], siz, target, numbers); // 빼기 
        backtraking(id+1, res + numbers[id], siz, target, numbers); // 더하기
    }
}