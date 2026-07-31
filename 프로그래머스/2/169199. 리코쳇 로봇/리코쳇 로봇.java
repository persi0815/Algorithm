import java.util.*; 

// 시작 위치에서 출발한 뒤 목표 위치에 정확하게 멈추기 위해 최소 몇 번의 이동이 필요한지 말하는 게임
class Solution {
    
    int[][] dyx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
    int[][] cost;
    int n, m;
        
    class Node{
        int y; int x; int c;
        public Node(int y, int x, int c){
            this.x = x; this.y = y; this.c = c; 
        }
    }
    public int solution(String[] board) {
        int answer = -1;
        
        n = board.length;
        m = board[0].length(); 
        
        int startY = -1; int startX = -1;  // R
        int targetY = -1; int targetX = -1;  // G
        
        // cost 배열 초기화
        cost = new int[n][m];
        for(int[] c : cost) Arrays.fill(c, Integer.MAX_VALUE); 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i].charAt(j) == 'D'){
                    cost[i][j] = -1;
                }else if(board[i].charAt(j) == 'R'){
                    startY = i; startX = j;
                }else if(board[i].charAt(j) == 'G'){
                    targetY = i; targetX = j; 
                }
            }
        }
        
        // 각 위치까지 몇 번만에 갈 수 있는지 bfs
        Queue<Node> q = new ArrayDeque<>(); 
        
        q.offer(new Node(startY, startX, 0)); 
        cost[startY][startX] = 0; 
        while(!q.isEmpty()){
            Node cur = q.poll(); 
            if(cur.y == targetY && cur.x == targetX){
                answer = cur.c;
                break;
            }
            // 다음 좌표
            for(int d = 0; d < 4; d++){
                int[] nxt = nextLoc(cur.y, cur.x, d);
                int ny = nxt[0]; int nx = nxt[1];
                if(cost[ny][nx] < cur.c + 1) continue; 
                
                cost[ny][nx] = cur.c + 1; 
                q.offer(new Node(ny, nx, cur.c + 1)); 
            }
        }
        
        return answer;
    }
    
    // 게임판 위의 장애물이나 게임판 가장자리까지 부딪힐 때까지 미끄러져 움직이는 것을 한 번의 이동으로 정의
    public int[] nextLoc(int y, int x, int d){
        while(true){
            int ny = y + dyx[d][0]; 
            int nx = x + dyx[d][1]; 
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) break;
            if(cost[ny][nx] == -1) break;
            
            y = ny; x = nx;
        }
        return new int[]{y, x};
    }
    
}