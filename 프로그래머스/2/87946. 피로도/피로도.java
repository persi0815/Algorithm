import java.util.*; 

class Node{
    int need; int lose; 
    public Node(int need, int lose){
        this.need = need; this.lose = lose; 
    }
}
class Solution {
    int dungeonsNum = -1;
    int maxDungeonNum = -1;
    boolean[] visited;
    
    //  bruteforce 시간 복잡도 가능하니 그걸로!
    public int solution(int k, int[][] dungeons) { // ["최소 필요 피로도", >= "소모 피로도"]
        dungeonsNum = dungeons.length; 
        visited = new boolean[dungeonsNum];
        
        goDungeons(k, 0, dungeons); 
        
        // 유저가 탐험할수 있는 최대 던전 수를 return 
        return maxDungeonNum;
    }
    
    
    // 순열로 bruteforce
    public void goDungeons(int kLeft, int visitedNum, int[][] dungeons){
        // 갱신
        maxDungeonNum = Math.max(maxDungeonNum, visitedNum); 
        
        // 새로운 던전 찾기
        for(int d = 0; d < dungeonsNum; d++){
            if(kLeft < dungeons[d][0]) continue; // 최소 피로도 부족
            if(!visited[d]){
                visited[d] = true;
                goDungeons(kLeft - dungeons[d][1], visitedNum+1, dungeons); // 피로도 소모
                visited[d] = false;
            }
        }
    }
}