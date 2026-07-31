import java.util.*; 

// 하루 동안 모든 게임 이용자가 게임을 하기 위해 서버를 최소 몇 번 증설해야 하는지 
class Solution {
    
    // 
    public int solution(int[] players, int m, int k) {
        // 서버 한 대로 감당할 수 있는 최대 이용자의 수를 나타내는 정수 m
        // 서버 한 대가 운영 가능한 시간을 나타내는 정수 k
        int answer = 0;
        
        Queue<Integer> q = new ArrayDeque<>(); // 언제까지 이용 가능한지
        
        // 각 시간대에 이용자 수 보고 늘려야 하면 늘리기
        for(int t = 0; t < players.length; t++){ // 1,000
            int playerNum = players[t]; 
            
            // 이용 불가능해진거 제거
            while(!q.isEmpty() && q.peek() < t){
                q.poll(); 
            }
            
            // 이용자 수 보고 부족하면 추가
            int need = (playerNum / m);
            int using = q.size(); 
            int more = need - using; 
            while(more-- > 0){
                q.offer(t + k -1); 
                answer++;
            }
            
        }
        
        
        // 모든 게임 이용자를 감당하기 위한 최소 서버 증설 횟수를 return
        return answer;
    }
}