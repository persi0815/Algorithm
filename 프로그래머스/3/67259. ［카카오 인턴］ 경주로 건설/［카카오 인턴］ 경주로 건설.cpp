#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
vector<vector<int>> dyx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
int solution(vector<vector<int>> board) {
    int answer = INT_MAX;
    int n = board.size();
    int score[n][n][4];// 해당 칸까지 가는데에 드는 비용
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int d = 0; d < 4; d++){
                score[i][j][d] = INT_MAX;
            }
        }
    }
    for(int i = 0; i < 4; i++){
        score[0][0][i] = 0; 
    }
    
    // 해당칸 까지 가는데에 소요되는 비용 계산
    queue<pair<pair<int, int>, int>> q; 
    // 동, 남 확인하고 넣기
    if(board[0][1] == 0) q.push({{0, 0}, 0});
    if(board[1][0] == 0) q.push({{0, 0}, 1});
    while(!q.empty()){
        auto f = q.front(); q.pop(); 
        int y = f.first.first; int x = f.first.second; 
        int dir = f.second; // 동서남북
        
        for(int i = 0; i < 4; i++){
            int ny = y + dyx[i][0]; 
            int nx = x + dyx[i][1]; 
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(board[ny][nx] == 1) continue;
            
            int s = ((dir+i)%2)==0 ? score[y][x][dir] + 100 : score[y][x][dir] + 600;
            if(score[ny][nx][i] > s){ // 기존 값보다 더 싼 값으로 갈 수 있으면
                score[ny][nx][i] = s; // 점수 갱신
                q.push({{ny, nx}, i});
            }
        }
    }
    
    
    // 견적서 작성을 위해 경주로를 건설하는 데 필요한 최소 비용
    for(int i = 0; i < 4; i++){
        answer = min(answer, score[n-1][n-1][i]);
    }
    return answer ;
}