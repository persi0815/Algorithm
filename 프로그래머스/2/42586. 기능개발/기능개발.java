import java.util.*; 

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        
        // 각각 몇일이 더 필요한지 계산
        int[] need = new int[progresses.length]; 
        for(int i = 0; i < progresses.length; i++){
            int todo = 100 - progresses[i];
            need[i] = (todo % speeds[i] == 0) ? 
                todo / speeds[i] : todo / speeds[i] + 1; 
        }
        
        // 각 배포마다 몇 개의 기능이 배포되는지
        List<Integer> answer = new ArrayList<>();
        int cur = need[0]; int cnt = 0; 
        for(int i = 0; i < progresses.length; i++){
            if(need[i] <= cur) cnt++;
            else {
                answer.add(cnt); 
                cur = need[i]; cnt = 1; 
            }
        }
        if(cnt != 0) answer.add(cnt); 
        
        
        return answer.stream(). mapToInt(i->i).toArray();
    }
}