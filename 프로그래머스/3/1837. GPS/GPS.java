import java.util.*; 

class Solution {
    int[][] cost; // 두 거점 사이의 최소 거리
    int[][] dp; // dp[t][v] 현재 택시가 v에 있다고 할때 0~t시점까지 필요한 최소 수정 수
    int INF = Integer.MAX_VALUE; 
    
    // 앞부터 가능한 모든 경우의 수를 다 고민해보자. 
    // 거점개수, 도로 개수, 도로 정보, 시간대별 정보 총 개수, 시간대별 정보
    public int solution(int n, int m, int[][] edge_list, int k, int[] gps_log) {
        cost = new int[n+1][n+1];
        
        // 연결리스트 만들기
        for(int i = 0; i < n
            +1; i++) {
            Arrays.fill(cost[i], INF); cost[i][i] = 0; 
        }
        for(int[] e : edge_list){
            cost[e[0]][e[1]] = 1; 
            cost[e[1]][e[0]] = 1; 
        }

        // dp
        dp = new int[k][n+1]; 
        for(int[] list : dp) Arrays.fill(list, INF); // 초기화
        dp[0][gps_log[0]] = 0; // 출발지만 0
        
        for(int t = 1; t < k; t++){ // 시점 t
            for(int v = 1; v <= n; v++){ // 택시 위치 v
                if(t == k-1 && gps_log[t] != v) continue; // 도착 위치는 고정이기에 다르면 continue;
                
                for(int bef = 1; bef <= n; bef++){
                    if(dp[t-1][bef] == INF) continue; // 이전 위치에 도달하지 못했다면 continue; 
                    if(cost[bef][v] > 1) continue; // 이전 위치에서 갈 수 없으면 continue;
                    
                    // 이전 위치에서 갈 수 있음 -> dp 갱신
                    if(v != gps_log[t]) dp[t][v] = Math.min(dp[t][v], dp[t-1][bef] + 1); // 지정된 위치가 아님 + 1
                    // 지정된 위치임 + 0
                    else dp[t][v] = Math.min(dp[t][v], dp[t-1][bef]);
                }
            }
        }
        
        // 택시가 보내온 경로에서 이동 가능한 경로로 만드는 최소의 오류 수정 횟수
        int answer = dp[k - 1][gps_log[k - 1]];
        return answer == INF ? -1 : answer;
    }

}