import java.util.*; 

class Data{
    int dir,  cost,  y,  x; 
    public Data(int dir, int cost, int y, int x){
        this.dir = dir; 
        this.cost = cost; 
        this.y = y; 
        this.x = x; 
    }
}

class Solution {
    
    int[][] dyx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
    Queue<Data> q = new LinkedList<>(); 
    
    // 경주로 건설
    public int solution(int[][] board) {
        int n = board.length; 
        int answer = 0;
        
        // 들어온 방향 고려! 비용 저장
        int[][][] c = new int[n][n][4]; // 기본으로 0으로 초기화
        for(int y = 0; y < n; y++){ // 초기화
            for(int x = 0; x < n; x++){
                for(int d = 0; d < 4; d++)
                    c[y][x][d] = Integer.MAX_VALUE; 
            }
        }
        
        // (0, 0)에서 bfs로 (n-1, n-1)로 이동
        q.offer(new Data(0, 0, 0, 0)); c[0][0][0] = 0; 
        q.offer(new Data(1, 0, 0, 0)); c[0][0][1] = 0; 
        while(!q.isEmpty()){
            Data t = q.peek(); q.poll(); 
            int dir = t.dir;
            int cost,  y,  x; 
            
            for(int d = 0; d < 4; d++){ // 진행 방향
                if(d == (t.dir + 2)%4) continue; // 되돌아가는 선택지 제거
                int[] yx = dyx[d];
                int ny = t.y + yx[0]; 
                int nx = t.x + yx[1]; 
                if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue; // 경계
                if(board[ny][nx] == 1) continue; // 벽
                
                // 비용 갱신
                if(d == t.dir){ // 직선
                    if(c[ny][nx][d] > (c[t.y][t.x][t.dir] + 100)){
                        c[ny][nx][d] = c[t.y][t.x][t.dir] + 100;
                        q.offer(new Data(d, c[t.y][t.x][t.dir] + 100, ny, nx));
                    }
                }
                else{ // 코너까지
                    if(c[ny][nx][d] > (c[t.y][t.x][t.dir] + 600)){
                        c[ny][nx][d] = c[t.y][t.x][t.dir] + 600;
                        q.offer(new Data(d, c[t.y][t.x][t.dir] + 600, ny, nx));
                    }
                }
                
            }
            
        }
        
        // 견적서 작성을 위해 경주로를 건설하는 데 필요한 최소 비용
        return answer = Arrays.stream(c[n-1][n-1]).min().getAsInt();
    }
}