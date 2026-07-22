import java.util.*;

class Solution {
    int n, m;
    int[][] dyx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
    Character[][] area;
    boolean[][][] visited; // 나가는거에 집중
    List<Integer> cycleLength;
    
    public void findCycleLen(int y, int x, int d){ // d: 들어오는 방향
        int len = 0; 
        // 이미 왔던 길이면 길이 확인 후 삽입
        while(!visited[y][x][d]) {
            // 현재 칸 처리
            visited[y][x][d] = true; 
            // 이번 방향
            char order = area[y][x];
            if (order == 'L') d = (d + 3) % 4;
            else if (order == 'R') d = (d + 1) % 4;
            // 이번 방향 -> 다음 칸
            y = (y + dyx[d][0] + n)%n; 
            x = (x + dyx[d][1] + m)%m;         
            // 다음칸으로 이동
            len++;
        }
        cycleLength.add(len);
    }
    
    public int[] solution(String[] grid) {
        cycleLength = new ArrayList<>(); 
        
        n = grid.length; 
        m = grid[0].length();
        
        // 배열 만들어 넣기
        area = new Character[n][m]; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                area[i][j] = grid[i].charAt(j);
            }
        }
        
        visited = new boolean[n][m][4];
        // 경로 찾기
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                for (int d = 0; d < 4; d++) {
                    if (!visited[y][x][d]) {
                        findCycleLen(y, x, d);
                    }
                }
            }
        }
        
        // 주어진 격자를 통해 만들어지는 빛의 경로 사이클의 모든 길이. 오름차순으로 정렬
        cycleLength.sort((a,b) -> {
            return a - b;
        });
        return cycleLength.stream().mapToInt(i->i).toArray();
    }
}