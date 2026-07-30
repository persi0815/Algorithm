import java.util.*; 

class Solution {
    
    int[][] dyx = {{0, 1}, {1, 0}}; 
    int[][] cost;
    int answer = 0;
    
    // 오른쪽과 아래쪽으로만 움직여 집에서 학교까지 갈 수 있는 최단경로의 개수를 1,000,000,007로 나눈 나머지
    public int solution(int m, int n, int[][] puddles) {
        
        cost = new int[n][m];
        // puddle 저장
        for(int[] p : puddles){
            int y = p[1]-1; int x = p[0]-1; 
            cost[y][x] = -1;
        }
        
        // 경로가 중요하니 dfs
        // dfs(0, 0, n, m);
        
        // DP로
        for(int i = 1; i < n; i++) {
            if(cost[i][0] != -1) cost[i][0] = 1;
            else break;
        }
        for(int i = 1; i < m; i++) {
            if(cost[0][i] != -1) cost[0][i] = 1;
            else break;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(!avail(i, j)) {
                    continue;
                }else if(!avail(i-1, j) && !avail(i, j-1)){
                    cost[i][j] = 0; 
                }else if(!avail(i-1, j)){
                    cost[i][j] = cost[i][j-1]; 
                }else if(!avail(i, j-1)){
                    cost[i][j] = cost[i-1][j];
                }else{
                    cost[i][j] = (cost[i-1][j] + cost[i][j-1]) % 1000000007;
                }
            }
        }
        
        return (cost[n-1][m-1]) % 1000000007;
    }
    
    public boolean avail(int y, int x){
        if(cost[y][x] == -1) return false;
        
        return true; 
    }
    
    public void dfs(int y, int x, int n, int m){
        // 끝까지 감
        if((y == n-1) && (x == m-1)){
            answer = ((answer+1) % 1000000007); 
            return;
        }
        // 다음 경로
        for(int d = 0; d < 2; d++){
            int ny = y + dyx[d][0]; 
            int nx = x + dyx[d][1]; 
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue; 
            if(cost[ny][nx] == -1) continue; 
            
            dfs(ny, nx, n, m);
        }
    }
}