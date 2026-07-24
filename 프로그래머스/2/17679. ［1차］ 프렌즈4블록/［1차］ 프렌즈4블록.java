import java.util.*; 

class Node{
    int y; int x; 
    public Node(int y, int x){
        this.y = y; this.x = x; 
    }
}
class Solution {
    int[][] dyx = {{0, 0}, {1, 0}, {0, 1}, {1, 1}}; 
    
    public int solution(int n, int m, String[] board) {
        int totalDeletedBlockNum = 0; // 지워지는 블록 개수
        
        // 보드 만들기
        Character[][] b = new Character[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                b[i][j] = board[i].charAt(j); 
            }
        }
        
        // 찾고 지우고 채우고 반복
        List<Node> delete = new ArrayList<>(); 
        while(true){ // 한 차례
            int deletedBlockNum = 0; 
            
            // 찾기 
            for(int i = 0; i < n-1; i++){
                for(int j = 0; j < m-1; j++){
                    // 비었다면 컨티뉴
                    if(b[i][j] == '-') continue;
                    // 넷 나머지 셋 중 하나라도 비었다면 컨티뉴
                    if(b[i+1][j] == '-' || b[i][j+1] == '-' || b[i+1][j+1] == '-') continue; 
                    // 넷 모두 같다면? 해당 (i,j)만 delete배열에 넣어두기
                    if(b[i][j] == b[i+1][j] && b[i][j] == b[i][j+1] && b[i][j] == b[i+1][j+1])
                        delete.add(new Node(i, j));
                }
            }
            
            // 지우기
            for(Node node : delete){ 
                int y = node.y; int x = node.x;
                // node(i, j)부터 시작하는 네칸 전부 -> '-'로
                for(int d = 0; d < 4; d++){
                    int ny = y+dyx[d][0];
                    int nx = x+dyx[d][1];
                    if(b[ny][nx] != '-'){
                        b[ny][nx] = '-'; // 갱신
                        deletedBlockNum++;
                    }else{ // 이미 지워짐
                        b[ny][nx] = '-'; // 갱신만
                    }
                } 
            }
            delete.clear(); // 초기화
            
            // 채우기
            for(int j = 0; j < m; j++){
                Node blank = new Node(-1, -1); // 열마다 초기화
                for(int i = n-1; i >=0; i--){ // 밑부터
                    // 빈칸이면
                    // blank가 없으면(-1)이면 갱신
                    // blank가 있다면 아무것도 x
                    if(b[i][j] == '-'){
                        if(blank.y == -1 && blank.x == -1){
                            blank.y = i; blank.x = j;
                        }
                    }
                    // 빈칸이 아니면 
                    // blank가 없으면(-1) 아무것도 x
                    // blank가 있으면 blank 위치에 해당 값 저장, blank--; => 떨어뜨리기
                    else{
                        if(blank.y != -1 && blank.x != -1){
                            b[blank.y][blank.x] = b[i][j]; // 빈칸에 넣음
                            b[i][j] = '-'; // 빈칸에 넣었으니 여긴 비워짐.
                            blank.y--; // 아래가 채워졌으니 빈칸은 올라감. 
                        }
                    }
                }
            }
            
            if(deletedBlockNum == 0) break; // 이번 차례에 못 찾음 -> 다음에도 없을 것.
            totalDeletedBlockNum += deletedBlockNum; // 지운 개수 갱신
        }
        
        // 지워지는 블록은 모두 몇 개인지 판단
        return totalDeletedBlockNum;
    }
}