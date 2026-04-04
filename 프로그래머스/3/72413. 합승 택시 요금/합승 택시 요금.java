import java.util.*;

class Node{
    int to; int cost; 
    Node(int to, int cost){
        this.to = to; 
        this.cost = cost;
    }
}
class Solution {
    
    int MAX_INT = Integer.MAX_VALUE;
    
    public int solution(int n, int s, int a, int b, int[][] fares) { // [c, d, f] 
        int answer = 0;
        
        int[][] dist = new int[n+1][n+1]; 
        for(int i = 1; i <= n; i++){
            Arrays.fill(dist[i], MAX_INT);
            dist[i][i] = 0;
        }

        for(int[] f : fares){
            int c = f[0]; int d = f[1]; int cost = f[2]; 
            dist[c][d] = cost; 
            dist[d][c] = cost; 
        }
        
        // 각 노드에서 각 노드로의 최소 비용 구하기 -> 플로이드 워셜
        for(int i = 1; i <= n; i++){ // 중간
            for(int j = 1; j <= n; j++){ // 시작
                for(int k = j+1; k <= n; k++){ // 끝
                    // 시작-끝 보다 시작-중간-끝이 더 짧으면 갱신
                    if(dist[j][i] == MAX_INT || dist[i][k] == MAX_INT) continue;  
                    if(dist[j][i] + dist[i][k] < dist[j][k]){
                        dist[j][k] = dist[j][i] + dist[i][k];
                        dist[k][j] = dist[j][i] + dist[i][k];
                    }
                    
                }
            }
        }
        
        // s부터 a, b까지의 최단 거리 구하기
        answer = dist[s][a] + dist[s][b];
        
        // s부터 중간 지점 -> a, b 최단 거리 구하기
        for(int i = 1; i <= n; i++){ // 중간 지점
            if(dist[s][i] == MAX_INT || dist[i][a] == MAX_INT || dist[i][b] == MAX_INT) continue;
            if(dist[s][i] + dist[i][a] + dist[i][b] < answer) {
                answer = dist[s][i] + dist[i][a] + dist[i][b];
            }
        }
        
        
        return answer; // 최저 예상 택시요금
    }
    
}