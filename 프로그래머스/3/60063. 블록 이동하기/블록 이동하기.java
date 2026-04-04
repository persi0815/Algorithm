import java.util.*; 

class Point{
    int y1; int x1; int y2; int x2; int dir;  // 위-아래, 왼-오
    Point(int y1, int x1, int y2, int x2, int dir){
        this.y1 = y1;
        this.x1 = x1; 
        this.y2 = y2; 
        this.x2 = x2;
        this.dir = dir;
    }
}

class Solution {
    int INF = 1_000_000;
    int[][][] cost;
    int[][] move = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public boolean isRange(int y, int x, int n) {
        return y >= 0 && y < n && x >= 0 && x < n;
    }
    
    public int solution(int[][] board) {
        int n = board.length;
        cost = new int[n][n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) Arrays.fill(cost[i][j], INF);
        }

        Queue<Point> q = new LinkedList<>();
        // 초기 상태: (0,0)-(0,1), 가로(0)
        q.offer(new Point(0, 0, 0, 1, 0));
        cost[0][0][0] = 0;

        while (!q.isEmpty()) {
            Point p = q.poll();
            int y1 = p.y1, x1 = p.x1, y2 = p.y2, x2 = p.x2, dir = p.dir;
            // 기준점의 비용을 가져옴 
            int curTime = cost[Math.min(y1, y2)][Math.min(x1, x2)][dir];

            if ((y1 == n - 1 && x1 == n - 1) || (y2 == n - 1 && x2 == n - 1)) return curTime;

            // 1. 이동
            for (int[] m : move) {
                int ny1 = y1 + m[0], nx1 = x1 + m[1];
                int ny2 = y2 + m[0], nx2 = x2 + m[1];
                if (isRange(ny1, nx1, n) && isRange(ny2, nx2, n) && board[ny1][nx1] == 0 && board[ny2][nx2] == 0) {
                    int ry = Math.min(ny1, ny2), rx = Math.min(nx1, nx2);
                    if (cost[ry][rx][dir] > curTime + 1) {
                        cost[ry][rx][dir] = curTime + 1;
                        q.offer(new Point(ny1, nx1, ny2, nx2, dir));
                    }
                }
            }

            // 2. 회전
            if (dir == 0) { // 가로 -> 세로
                for (int i : new int[]{-1, 1}) { // 위, 아래 회전
                    // 궤적 체크: 회전 방향의 두 칸이 모두 0이어야 함
                    if (isRange(y1 + i, x1, n) && isRange(y1 + i, x2, n) && board[y1 + i][x1] == 0 && board[y1 + i][x2] == 0) {
                        // 축 1 (y1, x1) 기준 / 축 2 (y2, x2) 기준
                        int[][] nexts = {{y1, x1, y1 + i, x1}, {y2, x2, y2 + i, x2}};
                        for (int[] next : nexts) {
                            int ry = Math.min(next[0], next[2]), rx = Math.min(next[1], next[3]);
                            if (cost[ry][rx][1] > curTime + 1) {
                                cost[ry][rx][1] = curTime + 1;
                                q.offer(new Point(next[0], next[1], next[2], next[3], 1));
                            }
                        }
                    }
                }
            } else { // 세로 -> 가로
                for (int i : new int[]{-1, 1}) { // 좌, 우 회전
                    if (isRange(y1, x1 + i, n) && isRange(y2, x1 + i, n) && board[y1][x1 + i] == 0 && board[y2][x1 + i] == 0) {
                        int[][] nexts = {{y1, x1, y1, x1 + i}, {y2, x2, y2, x2 + i}};
                        for (int[] next : nexts) {
                            int ry = Math.min(next[0], next[2]), rx = Math.min(next[1], next[3]);
                            if (cost[ry][rx][0] > curTime + 1) {
                                cost[ry][rx][0] = curTime + 1;
                                q.offer(new Point(next[0], next[1], next[2], next[3], 0));
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
}