import java.util.*; 

class Node{
    int y1; int x1; int y2; int x2; int dir;
    public Node(int y1, int x1, int y2, int x2, int dir){
        this.x1 = x1; this.y1 = y1; this.x2 = x2; this.y2 = y2; 
        this.dir = dir; 
    }
}

class Solution {
    
    public static int[][] dyx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
    public static int[][] hor_dyx = {
        { 1,  1, -1,  1}, // 위쪽 칸을 축으로 오른쪽 회전
        { 1, -1, -1, -1}, // 위쪽 칸을 축으로 왼쪽 회전
        { 1, -1, -1, -1}, // 아래쪽 칸을 축으로 왼쪽 회전
        { 1,  1, -1,  1}  // 아래쪽 칸을 축으로 오른쪽 회전
    };
    public static int[][] ver_dyx = {
        { 1,  1,  1, -1}, // 왼쪽 칸 축, 아래 회전
        {-1,  1, -1, -1}, // 왼쪽 칸 축, 위 회전
        {-1,  1, -1, -1}, // 오른쪽 칸 축, 위 회전
        { 1,  1,  1, -1}  // 오른쪽 칸 축, 아래 회전
    };    
    public static int b_len; 
    
    public boolean is_out_bounded(int y1, int x1, int y2, int x2){
        if(y1 < 0 || x1 < 0 || y2 < 0 || x2 < 0 || 
          y1 >= b_len || x1 >= b_len || y2 >= b_len || x2 >= b_len) return true;
        else return false; 
    }
    
    public boolean is_wall(int[][] board, int y1, int x1, int y2, int x2){
        if(board[y1][x1] == 1 || board[y2][x2] == 1) return true; 
        else return false; 
    }
    
    public int solution(int[][] board) {
        b_len = board.length;
        
        Queue<Node> q = new LinkedList<>(); 
        
        // 가로인지 세로인지가 cost에 영향을 줌 (특정 지점까지 갈 때의 비용이 다름)
        int[][][] min_cost = new int[b_len][b_len][2]; 
        for(int[][] b : min_cost){
            for(int[] bb : b)
                Arrays.fill(bb, Integer.MAX_VALUE); 
        }
        
        // 초기화
        q.offer(new Node(0, 0, 0, 1, 0)); 
        min_cost[0][0][0] = 0; 
        
        // bfs로 이동
        while(!q.isEmpty()){
            Node n = q.poll();
            
            // 기존점의 비용. 항상 상황을 특정할 수 있음.
            int curCost = min_cost[Math.min(n.y1, n.y2)][Math.min(n.x1, n.x2)][n.dir];
            
            // (n-1, n-1)에 도달했다면
            if ((n.y1 == b_len-1 && n.x1 == b_len-1) || (n.y2 == b_len-1 && n.x2 == b_len-1)) return curCost;

            
            // 가로, 세로 직선 이동
            for(int d = 0; d < 4; d++){
                int ny1 = n.y1 + dyx[d][0];
                int nx1 = n.x1 + dyx[d][1];
                int ny2 = n.y2 + dyx[d][0];
                int nx2 = n.x2 + dyx[d][1];
                if(is_out_bounded(ny1, nx1, ny2, nx2)) continue; // 지도 밖인가
                if(is_wall(board, ny1, nx1, ny2, nx2)) continue; // 이동할 곳
                
                int ry = Math.min(ny1, ny2), rx = Math.min(nx1, nx2);
                if(min_cost[ry][rx][n.dir] > curCost + 1){
                    min_cost[ry][rx][n.dir] = curCost + 1;
                    q.offer(new Node( ny1,nx1, ny2, nx2, n.dir));
                }
            }
            
            // 90도 회전
            for(int d = 0; d < 4; d++){
                int new_dir = (n.dir == 1) ? 0 : 1; // 회전 후 방향
                
                int ny1, nx1, ny2, nx2;
                // 가로 회전
                if(n.dir == 0){ 
                    ny1 = n.y1 + ver_dyx[d][0];
                    nx1 = n.x1 + ver_dyx[d][1];
                    ny2 = n.y2 + ver_dyx[d][2];
                    nx2 = n.x2 + ver_dyx[d][3];
                    if(is_out_bounded(ny1, nx1, ny2, nx2)) continue; // 이동 시 거치는 곳, 새롭게 가는 곳
                    if(is_wall(board, ny1, nx1, ny2, nx2)) continue;   
                }
                // 세로 회전
                else{ 
                    ny1 = n.y1 + hor_dyx[d][0];
                    nx1 = n.x1 + hor_dyx[d][1];
                    ny2 = n.y2 + hor_dyx[d][2];
                    nx2 = n.x2 + hor_dyx[d][3];
                    if(is_out_bounded(ny1, nx1, ny2, nx2)) continue; // 이동시 거치는 곳, 새롭게 가는 곳
                    if(is_wall(board, ny1, nx1, ny2, nx2)) continue; 
                }
                // 이동
                if(d < 2){ // x2, y2만 이동
                    int ry = Math.min(n.y1, ny2), rx = Math.min(n.x1, nx2);
                    if(min_cost[ry][rx][new_dir] > curCost + 1){
                        min_cost[ry][rx][new_dir] = curCost + 1;
                        if(d == 0) q.offer(new Node(n.y1, n.x1, ny2, nx2, new_dir)); 
                        else q.offer(new Node(ny2, nx2, n.y1, n.x1, new_dir)); 
                    }
                }else{ // x1, y1만 이동
                    int ry = Math.min(ny1, n.y2), rx = Math.min(nx1, n.x2);
                    if(min_cost[ry][rx][new_dir] > curCost + 1){
                        min_cost[ry][rx][new_dir] = curCost + 1;
                        if(d == 2) q.offer(new Node(ny1, nx1, n.y2, n.x2, new_dir)); 
                        else q.offer(new Node(n.y2, n.x2, ny1, nx1, new_dir)); 
                    }
                }   
            }
        }
        return -1;
    }
}