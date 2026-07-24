import java.util.*;

class Node{
    int y; int x; 
    public Node(int y, int x){
        this.y =y; this.x = x;
    }
}
class Solution {
    
    int nn, mm;
    int[][] visited; // 방문 여부 + 영역 번호 붙이기
    HashMap<Integer, Integer> extentMap = new HashMap<>(); // {영역 번호, 넓이}
    int[][] dyx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    public int[] solution(int n, int m, int[][] picture) {
        // 초기화
        visited = new int[n][m]; // 0
        nn = n; mm = m;
        
        // 영역 하나씩 보면서 안 채워져있으면 거기서부터 bfs 시작
        int num = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(picture[i][j] == 0) continue; // 색칠하지 않은 영역
                if(visited[i][j] > 0) continue; // 이미 영역표시를 한 영역
                int extent = bfs(i, j, num, picture); // 번호 매기기
                extentMap.put(num, extent); // 영역 개수 저장
                num++;
            }
        }
        
        // 가장 큰 넓이 찾기
        int numberOfArea = extentMap.size();
        List<Integer> extentList = new ArrayList<>(extentMap.values());
        extentList.sort((a, b) -> {
            return b-a; // 내림차순
        });
        int maxSizeOfOneArea = extentList.get(0);
        
        // 그림에 몇 개의 영역이 있는지와 가장 큰 영역의 넓이는 얼마인지
        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
    
    // 영역의 넓이 반환
    public int bfs(int y, int x, int num, int[][] picture){
        int color = picture[y][x]; 
        int extent = 1; // 시작점 포함
        Queue<Node> q = new ArrayDeque<>(); 
        
        q.offer(new Node(y, x)); visited[y][x] = num; 
        while(!q.isEmpty()){
            Node node = q.poll(); 
            
            for(int d = 0; d < 4; d++){
                int ny = node.y + dyx[d][0]; 
                int nx = node.x + dyx[d][1];
                if(ny < 0 || nx < 0 || ny >= nn || nx >= mm) continue; // 경계 밖
                if(picture[ny][nx] != color) continue; // 같은 색이 아님
                if(visited[ny][nx] != 0) continue; // 방문했었음
                
                visited[ny][nx] = num; // 영역 표시
                extent++; // 영역 개수 늘리기
                q.offer(new Node(ny, nx)); 
            }
        }
        
        
        return extent;
    }
    
}