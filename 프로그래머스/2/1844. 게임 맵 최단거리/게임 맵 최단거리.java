import java.util.*; 
/*
상대 진영 먼저 파괴하면 이김 -> 상대 진영에 최대한 빨리 도착해야 함. 

*/
class Coor{
    int x; 
    int y;
    int dist;
    
    public Coor(int y, int x, int dist){
        this.x = x;
        this.y = y;
        this.dist = dist;
    }
}

class Solution {
    int[][] dyx = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    public int bfs(int[][] maps){
        boolean[][] visited = new boolean[maps.length][maps[0].length];
        Queue<Coor> q = new LinkedList<>();
        q.add(new Coor(0, 0, 1)); 
        
        while(!q.isEmpty()){
            Coor coor = q.poll();
            int y = coor.y; int x = coor.x; int dist = coor.dist;
            if(y == maps.length - 1 && x == maps[0].length - 1) return dist;
            
            for(int i = 0; i < 4; i++){
                int ny = y + dyx[i][0]; int nx = x + dyx[i][1];
                if(ny < 0 || nx < 0 || ny >= maps.length || nx >= maps[0].length) continue;
                if(maps[ny][nx] == 0) continue;
                if(!visited[ny][nx]){
                    visited[ny][nx] = true; 
                    q.add(new Coor(ny, nx, dist+1));
                }
            }
            
        }
        return -1;
    }
    
    // 게임 맵의 상태. 캐릭터가 상대 팀 진영에 도착하기 위해 지나가야 하는 칸의 최솟값은? 
    public int solution(int[][] maps) { // 0: 벽 o. 1: 벽 x
        
        int answer = bfs(maps);
        
        return answer;
    }
}