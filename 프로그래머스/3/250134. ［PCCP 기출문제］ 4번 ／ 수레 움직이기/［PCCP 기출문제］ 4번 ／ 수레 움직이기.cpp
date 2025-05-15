#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<pair<int, int>> dyx = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
vector<vector<pair<int, int>>> visited; // 빨, 파
int ans = INT_MAX;

bool can_move(int ny, int nx, vector<vector<int>>& maze, int n, int m){
    if(ny < 0 || nx < 0 || ny >= n || nx >= m || maze[ny][nx] == 5) return false; 
    else return true; 
}

// 빨: 1 -> 3 파: 2 -> 4 / 벽: 5
void move(vector<vector<int>>& maze, 
         pair<int, int>r_now, pair<int, int>b_now, 
         const pair<int, int>r_end, const pair<int, int>b_end, 
         int n, int m, int cnt)
{
    if(cnt >= ans) return; // 최솟값 넘으면 컷
    
    // 도착했다면 
    if(r_now == r_end && b_now == b_end){
        ans = min(ans, cnt); 
        return; 
        
    }else if(r_now == r_end){
        for(int j = 0; j < 4; j++){
            int ny = b_now.first + dyx[j].first; 
            int nx = b_now.second + dyx[j].second;
            
            if(!can_move(ny, nx, maze, n, m) || visited[ny][nx].second) continue;
            if (make_pair(ny, nx) == r_now) continue; // 둘이 겹침 금지
            
            visited[ny][nx].second = true; 
            move(maze, r_now, {ny, nx}, r_end, b_end, n, m, cnt+1);
            visited[ny][nx].second = false; 
        }
    }else if(b_now == b_end){
        for(int j = 0; j < 4; j++){
            int ny = r_now.first + dyx[j].first; 
            int nx = r_now.second + dyx[j].second;
            
            if(!can_move(ny, nx, maze, n, m) || visited[ny][nx].first) continue;
            if (make_pair(ny, nx) == b_now) continue; // 둘이 겹침 금지
            
            visited[ny][nx].first = true; 
            move(maze, {ny, nx}, b_now, r_end, b_end, n, m, cnt+1);
            visited[ny][nx].first = false; 
        }
    }else{
        for(int i = 0; i < 4; i++){
            int ny = r_now.first + dyx[i].first; 
            int nx = r_now.second + dyx[i].second;
            if(!can_move(ny, nx, maze, n, m) || visited[ny][nx].first) continue; 
            visited[ny][nx].first = true; 
            
            for(int j = 0; j < 4; j++){
                int nny = b_now.first + dyx[j].first; 
                int nnx = b_now.second + dyx[j].second;
                if(!can_move(nny, nnx, maze, n, m) || visited[nny][nnx].second) continue; 
                // 서로 경로 swap 이면 안됨
                if(ny == b_now.first && nx == b_now.second
                  && nny == r_now.first && nnx == r_now.second) continue;
                
                // 둘이 같은 곳으로 가면 안됨
                if(ny == nny && nnx == nx) continue;
                
                visited[nny][nnx].second = true; 
                move(maze, {ny, nx}, {nny, nnx}, r_end, b_end, n, m, cnt+1);
                visited[nny][nnx].second = false; 
            }
            visited[ny][nx].first = false; 
        }
    }
}
int solution(vector<vector<int>> maze) {
    int answer = 0; // 퍼즐 푸는데 필요한 턴의 최솟값
    int n = maze.size(); // 행
    int m = maze[0].size(); // 열
    visited.resize(n, vector<pair<int, int>>(m, {false, false})); // 방문 표시
    
    pair<int, int> red_start; pair<int, int> red_end; 
    pair<int, int> blue_start; pair<int, int> blue_end;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            if(maze[i][j] == 1) {
                red_start = {i, j}; visited[i][j].first = true;
            }
            else if(maze[i][j] == 2) {
                blue_start = {i, j}; visited[i][j].second = true;
            }
            else if(maze[i][j] == 3) red_end = {i, j}; 
            else if(maze[i][j] == 4) blue_end = {i, j}; 
        }
    }
    
    
    // 이동 횟수 구하기
    int cnt = 0; // 이동 횟수
    move(maze, red_start, blue_start, red_end, blue_end, n, m, cnt); 
    answer = (ans == INT_MAX) ? 0 : ans;
    return answer;
}