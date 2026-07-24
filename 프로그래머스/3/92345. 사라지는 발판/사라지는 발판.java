import java.util.*;

class Result{
    boolean win; int leftByEnd; 
    public Result(boolean win, int leftByEnd){
        this.win = win; this.leftByEnd = leftByEnd;
    }
}
class Loc{
    int y; int x;
    public Loc(int y, int x){
        this.y = y; this.x =x;
    }
}
class Solution {
    int[][] dyx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
    int n, m;
    
    public int solution(int[][] board, int[] aloc, int[] bloc) {
        n = board.length; 
        m = board[0].length;
        int ay = aloc[0]; int ax = aloc[1]; int by = bloc[0]; int bx = bloc[1]; 
        
        // {현재 player 승or패, 종료까지 남은 횟수} = dfs(남아있는 발판, 내 위치, 상대 위치);    
        Result res = dfs(board, new Loc(ay, ax), new Loc(by, bx));
        
        
        // 양 플레이어가 최적의 플레이를 했을 때, 두 캐릭터가 움직인 횟수의 합을 return
        return res.leftByEnd;
    }
    
    public Result dfs(int[][] board, Loc me, Loc other){ // 내 차례
        
        if(board[me.y][me.x] == 0) return new Result(false, 0); // 밟고 있던 칸이 사라짐
        
        boolean moveAvail = false; // 네 방향 중에 하나라도 갈 수 있음(지더라도)
        boolean canWin = false;
        int minWin = Integer.MAX_VALUE;  // 승리할때 최소 횟수
        int maxLose = 0;  // 패배할때 최대 횟수
        
        board[me.y][me.x] = 0; // 나의 cur 발판 제거
        
        for(int d = 0; d < 4; d++){
            int ny = me.y + dyx[d][0]; 
            int nx = me.x + dyx[d][1];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue; // 경계 벗어남
            if(board[ny][nx] == 0) continue; // 발판 없음
            moveAvail = true; // 이동 가능
                
            //{현재 player 승or패, 종료까지 남은 횟수} = dfs(남아있는 발판, 상대 위치, nxt); 
            Result res = dfs(board, other, new Loc(ny, nx)); 
                
            if(!res.win){ // 상대 패 -> 이길 수 있는 최소 횟수 갱신
                canWin = true;
                minWin = Math.min(minWin, res.leftByEnd);
            }
            else{ // 상대 승 -> 질 수 있는 최대 횟수 갱신 (최대한 버팀)
                maxLose = Math.max(maxLose, res.leftByEnd);
            } 
        }
        board[me.y][me.x] = 1; // 나의 현재 발판 복구
            
        if(!moveAvail) return new Result(false, 0); // 이동할 칸이 없음
            
        if (canWin) { // 이길 수 있다면
            return new Result(true, minWin + 1);
        } else { // 무조건 진다면
            return new Result(false, maxLose + 1);
        }
        

    }
}