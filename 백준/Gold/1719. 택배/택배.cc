#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
/*
어떤 경로를 거쳐야 하는가? 
가중치 = 이동에 걸리는 시간. 
행 -> 열의 잡하장으로 화물을 이동시키기 위해 가장 먼저 거쳐야 하는 집하장
=> 경로표 구하기 = 어디서 어디로 갈때 가장 먼저 거쳐야 하는 집하장 구하기
한 점에서 모든 정점으로 가야함.
*/

int n, m; // 잡하장의 개수. 집하장간의 경로의 개수

vector<int> get_route(int st, int n, vector<vector<pair<int, int>>>& route){
    // 해당 시작점에서 모든 끝지점까지의 최단 경로 구하기
    vector<int> dist(n+1, INT_MAX); 
    vector<int> first(n+1, -1); // 첫 이동 지점 기록
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
    // {거리, 현재 위치}

    dist[st] = 0; 
    first[st] = 0;
    pq.push({0, st}); 
    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        int d = t.first; int cur = t.second; 

        if (d > dist[cur]) continue;

        for(int i = 0; i < route[cur].size(); i++){
            int next = route[cur][i].first; 
            int cost = route[cur][i].second;

            if(dist[next] > d + cost){
                dist[next] = d + cost; 
                pq.push({d+cost, next}); 

                if(cur == st) first[next] = next; 
                else first[next] = first[cur]; // 이전 지점 위치 복사
            }
            
        }
    }
    return first;
    
}

int main() {
    cin >> n >> m; 
    vector<vector<pair<int, int>>> route(n+1); 
    vector<vector<int>> ans(n+1); 
    for(int i = 0; i < m; i++){ // 10,000
        int a, b, c; cin >> a >> b >> c; 
        route[a].push_back({b, c}); 
        route[b].push_back({a, c}); 
    }

    // 시작점 하나 잡고
    // 모든 점을 각각 도착지로 잡았을 때 최단 경로는 무엇이고, 첫 집하장은 어디인가
    for(int st = 1; st <= n; st++){ // 200
        ans[st] = get_route(st, n, route); 
    }

    // 출력
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) cout << '-' << " ";
            else cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}