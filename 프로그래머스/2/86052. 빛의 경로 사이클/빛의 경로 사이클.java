import java.util.*; 

class Node{
    int y; int x; int dir; int cost; 
    Node(int y, int x, int dir, int cost){
        this.y = y; 
        this.x = x; 
        this.dir = dir; 
        this.cost = cost;
    }
}
class Solution {
    // 선언
    int n, m;
    char[][] direction;
    int[][][] area;
    int[][] dyx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // RDLU
    
    int bfs(int i, int j, int d, int num) {
        int y = i, x = j, dir = d;
        int cost = 0;

        while (true) {
            // 방문 표시 및 거리 증가
            area[y][x][dir] = num;
            cost++;

            // 현재 칸의 문자에 따라 '다음 나갈 방향' 결정
            char direc = direction[y][x];
            if (direc == 'L') dir = (dir + 3) % 4;
            else if (direc == 'R') dir = (dir + 1) % 4;

            // 결정된 방향으로 한 칸 이동 및 워프 적용
            y = (y + dyx[dir][0] + n) % n;
            x = (x + dyx[dir][1] + m) % m;

            // 시작점과 시작 방향으로 완전히 돌아왔다면 종료
            if (y == i && x == j && dir == d) return cost;
        }
    }
    
    public int[] solution(String[] grid) {
        List<Integer> answer = new ArrayList<>(); 
        n = grid.length; 
        m = grid[0].length(); 
        
        area = new int[n][m][4]; // 행 열 들어오는 방향
        direction = new char[n][m]; // 방향
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                direction[i][j] = grid[i].charAt(j);
            }
        }
        
        // 출발지 선택해서 경로 표시
        int curr_num = 1; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int d = 0; d < 4; d++){
                    if(area[i][j][d] != 0) continue; // 이미 지나갔던 길이니 표시x
                    answer.add(bfs(i, j, d, curr_num++));
                }
            }
        }
        
        
        // 빛의 경로 사이클의 모든 길이들을 배열에 담아 오름차순으로 정렬
        answer.sort((a, b) -> a-b);
        return answer.stream().mapToInt(i->i).toArray();
    }
}