import java.util.*; 

class Solution {
    HashSet<String> wordStack = new HashSet<>(); 
    
    public int[] solution(int n, String[] words) {
        int[] answer = {};
        int failNum = -1; 
        
        int turn = 1; 
        char bef = words[0].charAt(0); // 직전에 나왔던 문자
        int id = 0;
        
        while(turn <= words.length / n + 1){
            
            for(int i = 0; i < n; i++){
                id = (turn-1) * n + i;
                if(id >= words.length) return new int[]{0, 0};
                
                // 직전에 나왔던 문자로 시작하는지
                // 같은거 반복되진 않았는지
                if(words[id].charAt(0) != bef || wordStack.contains(words[id])){
                    failNum = i; break; 
                }else{
                    bef = words[id].charAt(words[id].length()-1); 
                    wordStack.add(words[id]);
                }
               
            }
            if(failNum != -1) break;
            
            turn++;
        }

        

        // 가장 먼저 탈락하는 사람의 번호와 그 사람이 자신의 몇 번째 차례에 탈락하는지를 구해서 return
        return new int[]{failNum+1, turn};
    }
}