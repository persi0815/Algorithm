#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm> // min_element

using namespace std;

vector<pair<int, int>> dyx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // RDLU

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size(); 
    
    // (0, 0) -> (N-1, N-1) 까지 BFS. 각 칸의 최소 비용 cost에 적재!
    int c[n][n][4]; 
    queue< pair< pair<int, int>, pair<int, int> > > q; // {{y, x}, {dir, cost}} 
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 4; k++){
                c[i][j][k] = INT_MAX; 
            }
        }
    }
    q.push({{0, 0}, {1, 0}}); q.push({{0, 0}, {0, 0}}); 
    c[0][0][0] = 0; c[0][0][1] = 0; c[0][0][2] = 0; c[0][0][3] = 0; 
    
    while(!q.empty()){
        auto f = q.front(); q.pop(); 
        int y = f.first.first; int x = f.first.second; 
        int dir = f.second.first; int cost = f.second.second; 
        
        for(int d = 0; d < 4; d++){
            int ny = y + dyx[d].first; 
            int nx = x + dyx[d].second; 
            if(ny >= n || nx >= n || ny < 0 || nx < 0) continue; 
            if(board[ny][nx] == 1) continue; // 벽
            if((dir+2)%4 == d) continue; // 거꾸로
            if(dir == d && c[ny][nx][d] > (cost + 100)){ // 직전
                c[ny][nx][d] = cost + 100; 
                q.push({{ny, nx}, {d, cost+100}}); 
            } else if(dir != d && c[ny][nx][d] > (cost + 600)){ // 꺽기
                c[ny][nx][d] = cost + 600; 
                q.push({{ny, nx}, {d, cost+600}});
            }
        }
    }
    
    // 경주로를 건설하는 데 필요한 최소 비용
    return answer = *min_element(c[n-1][n-1], c[n-1][n-1]+4);
}