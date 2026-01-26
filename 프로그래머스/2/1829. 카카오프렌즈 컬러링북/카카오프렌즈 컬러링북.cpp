#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> area_size;  // 영역 변호: 개수
vector<vector<int>> area;
vector<pair<int, int>> dyx = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(int yy, int xx, int num, vector<vector<int>>& picture){
    int color = picture[yy][xx];
    
    queue<pair<int, int>> q;
    q.push({yy, xx});
    area[yy][xx] = num;
    int size = 1; 
    
    while(!q.empty()){
        auto now = q.front(); q.pop();
        int y = now.first; int x = now.second;
            
        for(int i = 0; i < 4; i++){
            int new_y = y + dyx[i].first;
            int new_x = x + dyx[i].second;
            if(new_y < 0 || new_x < 0 || new_y >= area.size() || new_x >= area[0].size()) continue; 
            
            if(area[new_y][new_x] == -1){ // 방문 확인
                if(picture[new_y][new_x] == color) { // 색 확인
                    area[new_y][new_x] = num;
                    size++;
                    q.push({new_y, new_x}); 
                }
            }
        }
    }
    return size;
}

// 영역 개수, 가장 큰 영역 넓이
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    area.clear();
    area_size.clear();
    
    area.resize(m, vector<int> (n, -1));
    int area_num = 0;
    
    // 하나씩 돌면서 아직 구역 지정이 안됐으면 해당 지점부터 같은 색 bfs 탐색 -> 설정
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(area[i][j] == -1 && picture[i][j] != 0){ // 아직 방문 안했고, 색이 0이 아니라면
                area_size.push_back(bfs(i, j, area_num++, picture));
            }
        }
    }
    
    // 영역 개수 찾고, 가장 큰 영역 넓이 구하기
    int max_size = *max_element(area_size.begin(), area_size.end());
    
    return {area_num, max_size};
}