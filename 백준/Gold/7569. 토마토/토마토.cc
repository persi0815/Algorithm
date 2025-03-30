#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;
/*
익은 토마토들의 인접한 곳에 있는 익지 않는 토마토들은 익은 토마토의 영향을 받아 익는다. 인접 = 위, 아래, 왼, 오, 앞, 뒤
토마토들이 며칠이 지나면 다 익게 되는지 최소 일수 알고자 -> bfs
*상자의 일부 칸에는 토마토가 들어있지 않을 수 있다. 

*/
int m, n, h; // 상자의 크기, 상자의 수
int tomato[100][100][100];
int not_ripe = 0;
queue<tuple<int, int, int, int>> q; // day, h, y, x
int res_day = 0;
vector<pair<int, pair<int, int>>> dhyx = {
    {0, {0, 1}}, {0, {1, 0}}, {0, {-1, 0}}, {0, {0, -1}}, 
    {1, {0, 0}}, {-1, {0, 0}}
    };

int main(){
    cin >> m >> n >> h;
    // 입력
    for(int i = 0; i < h; i++){ // 높이
        for(int j = 0; j < n; j++){ // 세로
            for(int k = 0; k < m; k++){ // 가로
                cin >> tomato[i][j][k];
                // 1: 익은, 0: 익지 x, -1: 없음
                if(tomato[i][j][k] == 1)
                    q.push({0, i, j, k});
                if(tomato[i][j][k] == 0)
                    not_ripe++;
            }
        }
    } 
    //cout << not_ripe << endl;
    if(not_ripe == 0) {
        cout << 0; // 이미 다 익어있음
        exit(0); // 종료
    }
    
    // 반복하며 토마토 익히기
    while(!q.empty()){
        auto t = q.front();
        int day = get<0>(t); int hh = get<1>(t); 
        int y = get<2>(t); int x = get<3>(t);
        q.pop();
        
        for(int i = 0; i < 6; i++){
            int n_h = hh + dhyx[i].first;
            int n_y = y + dhyx[i].second.first;
            int n_x = x + dhyx[i].second.second;
            if(n_h < 0 || n_h >= h || n_y < 0 || n_y >= n || n_x < 0 || n_x >= m)
                continue;
            if(tomato[n_h][n_y][n_x] == 0) {
                //cout << n_h << " " << n_y << " " << n_x << endl;
                tomato[n_h][n_y][n_x] = 1;
                q.push({day+1, n_h, n_y, n_x});
                res_day = max(res_day, day+1);
                not_ripe--;
            }
            
        }
    }
    //cout << not_ripe << endl;

    
    // 소요되는 날 출력 (익지 못한다면 -1)
    if(not_ripe > 0) cout << -1 << endl;    
    else cout << res_day << endl;
}
