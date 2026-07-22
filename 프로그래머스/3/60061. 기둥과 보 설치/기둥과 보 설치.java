import java.util.*;

class Solution {
    boolean[][][] frame;
    int nn;
    
    // 기둥: 바닥 위에 있거나 / 보의 한쪽 끝 부분 위에 있거나 / 다른 기둥 위에 있어야
    public boolean isColumnOkay(int y, int x){
        if(y == 0) return true; 
        if(frame[y][x][1] || (x-1 >=0 && frame[y][x-1][1])) return true; 
        if(y-1 >= 0 && frame[y-1][x][0]) return true; 
        return false;
    }
    
    // 보: 한쪽 끝 부분이 기둥 위에 있거나 / 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야
    public boolean isFloorOkay(int y, int x){
        if((y-1 >= 0 && frame[y-1][x][0]) || (y-1 >= 0 && x+1 <= nn && frame[y-1][x+1][0])) return true; 
        if((x-1 >= 0 && frame[y][x-1][1]) && (x+1 <= nn && frame[y][x+1][1])) return true; 
        return false;
    }
    
    // 나머지 전부 괜찮은지 확인
    public boolean isAllOkay(){
        for(int i = 0; i <= nn; i++){
            for(int j = 0; j <= nn; j++){
                if(frame[i][j][0]) if(!isColumnOkay(i, j)) return false;
                if(frame[i][j][1]) if(!isFloorOkay(i, j)) return false;
            }
        }
        return true;
    }
    
    public int[][] solution(int n, int[][] build_frame) {
        nn = n;
        
        frame = new boolean[n+1][n+1][2]; 
        List<int[]> ans = new ArrayList<>();
        // build_frame 하나씩 돌며 가능한지 확인 후 가능하다면 반영
        for(int[] build : build_frame){ // 1000 * 1000
            int x = build[0]; int y = build[1]; int a = build[2]; int b = build[3]; 
            
            if(b == 0){ // 삭제
                // 삭제
                frame[y][x][a] = false; 
                // 나머지들이 괜찮은지 확인
                if(!isAllOkay()) frame[y][x][a] = true;
                
            }else{ // 설치
                if(a == 0){ // 기둥
                    // 설치
                    frame[y][x][a] = true; 
                    // 괜찮은지 확인
                    if(!isColumnOkay(y, x)) frame[y][x][a] = false; 
                }else{ // 보
                    // 설치
                    frame[y][x][a] = true; 
                    // 괜찮은지 확인
                    if(!isFloorOkay(y, x)) frame[y][x][a] = false; 
                }
            }
        }
        
        // ans에 삽입
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(frame[i][j][0]) ans.add(new int[]{j, i, 0});
                if(frame[i][j][1]) ans.add(new int[]{j, i, 1});
            }
        }
        
        
        // x좌표 기준으로 오름차순 정렬하며, x좌표가 같을 경우 y좌표 기준으로 오름차순 정렬
        ans.sort((a, b) -> {
            if(a[0]!=b[0]) return a[0] - b[0]; 
            else if(a[1]!=b[1]) return a[1] - b[1];
            else return a[2] - b[2];
        });
        
        // 모든 명령어를 수행한 후 구조물의 상태를 return
        int[][] answer = new int[ans.size()][3]; 
        for(int i = 0; i < ans.size(); i++){
            answer[i] = ans.get(i);
        }
        return answer;
    }
}