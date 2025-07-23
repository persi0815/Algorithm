import java.util.*;

class Coor {
    int x, y, dist;

    public Coor(int y, int x, int dist) {
        this.x = x;
        this.y = y;
        this.dist = dist;
    }
}

class Solution {
    int[][] dyx = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // 하우상좌

    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int[][] block = new int[102][102]; // 좌표 2배 확장
        boolean[][] visited = new boolean[102][102];

        // 1. 전체 사각형 그리기 (2배 확대)
        for (int[] rec : rectangle) {
            int x1 = rec[0] * 2, y1 = rec[1] * 2;
            int x2 = rec[2] * 2, y2 = rec[3] * 2;

            for (int y = y1; y <= y2; y++) {
                for (int x = x1; x <= x2; x++) {
                    block[y][x] = 1;
                }
            }
        }

        // 2. 내부 비우기
        for (int[] rec : rectangle) {
            int x1 = rec[0] * 2, y1 = rec[1] * 2;
            int x2 = rec[2] * 2, y2 = rec[3] * 2;

            for (int y = y1 + 1; y < y2; y++) {
                for (int x = x1 + 1; x < x2; x++) {
                    block[y][x] = 0; // 내부 제거
                }
            }
        }

        // 3. BFS 시작
        Queue<Coor> q = new LinkedList<>();
        int sy = characterY * 2, sx = characterX * 2;
        int ey = itemY * 2, ex = itemX * 2;

        q.add(new Coor(sy, sx, 0));
        visited[sy][sx] = true;

        while (!q.isEmpty()) {
            Coor curr = q.poll();

            if (curr.y == ey && curr.x == ex) {
                return curr.dist / 2; // 2배 했으니 다시 2로 나눔
            }

            for (int[] d : dyx) {
                int ny = curr.y + d[0];
                int nx = curr.x + d[1];

                if (ny < 0 || ny >= 102 || nx < 0 || nx >= 102) continue;
                if (visited[ny][nx]) continue;
                if (block[ny][nx] != 1) continue;

                visited[ny][nx] = true;
                q.add(new Coor(ny, nx, curr.dist + 1));
            }
        }

        return -1; // 못 찾은 경우
    }
}
