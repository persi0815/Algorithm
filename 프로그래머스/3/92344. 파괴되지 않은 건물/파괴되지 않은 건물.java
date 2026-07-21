class Solution {
    public int solution(int[][] board, int[][] skill) {
        int answer = 0;
        int n = board.length; 
        int m = board[0].length;
        
        int[][] b = new int[n][m];
        
        for(int[] s : skill){
            int type = s[0]; 
            int y1 = s[1]; int x1 = s[2]; int y2 = s[3]; int x2 = s[4];
            int degree = s[5]; 
            
            if(type == 1){ // 공격
                b[y1][x1] += -1 * degree; 
                if(x2+1 < m) b[y1][x2+1] += degree; 
                if(y2+1 < n) b[y2+1][x1] += degree; 
                if(x2+1 < m && y2+1 < n) b[y2+1][x2+1] += -1 * degree;
            }else{ // 회복
                b[y1][x1] += degree; 
                if(x2+1 < m) b[y1][x2+1] += -1 * degree; 
                if(y2+1 < n) b[y2+1][x1] += -1 * degree; 
                if(x2+1 < m && y2+1 < n) b[y2+1][x2+1] += degree;
            }
        }
        
        // 누적합 계산
        for(int i = 0; i < board.length; i++){
            for(int j = 1; j < b[0].length; j++){
                b[i][j] += b[i][j-1];
            }
        }
        for(int j = 0; j < board[0].length; j++){
            for(int i = 1; i < b.length; i++){
                b[i][j] += b[i-1][j];
            }
        }
        
        // 파괴되지 않은 건물 세기
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(b[i][j] + board[i][j] > 0) answer++;
            }
        }
        
        // 적의 공격 혹은 아군의 회복 스킬이 모두 끝난 뒤 파괴되지 않은 건물의 개수를 return
        return answer;
    }
}