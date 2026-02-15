#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// start, end, cost
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    
    // 모든 노드에서 다른 모든 노드로 가는 최단 거리 파악
    int graph[n+1][n+1];
    for(auto& g:graph){
        fill(g, g+n+1, 20000001);
    }
    for(int i = 1; i <= n; i++){
        graph[i][i] = 0;
    }
    for(auto&f: fares){
        int st = f[0]; int end = f[1]; int cost = f[2]; 
        graph[st][end] = cost; graph[end][st] = cost;
    }
    
    // 플로이드워셜로 모든 노드에서 모든 노드로 가는 최단 거리 계산
    for(int i = 1; i <= n; i++){ // 거쳐가는 노드
        for(int start = 1; start <= n; start++){
            for(int end = 1; end <= n; end++){
                graph[start][end] = 
                    min(graph[start][end], graph[start][i] + graph[i][end]);
            }
        }
    }
    
    // a와 b에서 1~n까지의 중간 지점 정해놓고 비용 판단
    for(int i = 0; i <= n; i++){
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]); 
    }
    // 그냥 s -> a, s -> b
    answer = min(answer, graph[s][a]+graph[s][b]);
    
    // 최저 예상 택시요금을 계산해서 return
    return answer;
}