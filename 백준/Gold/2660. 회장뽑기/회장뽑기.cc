#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
/*
각 회원은 다른 회원들과 가까운 정도에 따라 점수를 받게 된다. 
회장은 회원들 중 점수가 가장 작은 사람
=> 회장의 점수와 회장이 될 수 있는 모든 사람 찾기

모든 사람이 다른 모든 사람과의 관계가 어떤가? 
최단 depth들을 구했을때 가장 큰 값 = 점수

-> 최종적으로는 각 사람들의 점수 도출 -> 가장 작은 점수 가진 사람 선별
*/

int n; 

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; // 회원의 수
    
    vector<vector<int>> dist(n+1, vector<int>(n+1, INT_MAX)); // 관계 최단 거리
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    
    while(true){
        int a, b; cin >> a >> b; 
        if(a == -1 && b == -1) break; 
        dist[a][b] = 1; dist[b][a] = 1;
    }

    for(int k = 1; k <= n; k++){ // 경유지
        for(int i = 1; i <= n; i++){ // 출발지
            for(int j = 1; j <= n; j++){ // 도착지
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                if(dist[i][j] == INT_MAX || dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j]; // 더 짧아짐.
                }
                
            }
        }
    }

    vector<pair<int, int>> res;
    for(int i = 1; i <= n; i++){ // 누구? 
        int score = 0;
        bool possible = true;
        for(int j = 1; j <= n; j++){ // 친구와의 거리
            if(dist[i][j] == INT_MAX) {
                possible = false;
                break;
            }
            score = max(score, dist[i][j]); 
        }
        if (possible) res.push_back({score, i});
    }

    sort(res.begin(), res.end()); // 오름차순 정렬

    // 회장 후보의 점수, 후보의 수
    int leader_score = res[0].first;
    cout << leader_score << " "; 
    
    vector<int> leader;
    for(int i = 0; i < n; i++){
        if(res[i].first == leader_score) leader.push_back(res[i].second); 
        else break; 
    }
    cout << leader.size() << endl; 
    
    // 회장 후보 오름차순으로 출력
    sort(leader.begin(), leader.end()); 
    for(int i = 0; i < leader.size(); i++){
        cout << leader[i] << " ";
    }

    return 0;
}
