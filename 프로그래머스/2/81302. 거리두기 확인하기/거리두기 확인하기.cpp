#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 거리두기를 위하여 응시자들 끼리는 맨해튼 거리가 2 이하로 앉지 않도록
// 응시자가 앉아있는 자리 사이가 파티션으로 막혀 있을 경우에는 허용
vector<vector<char>> area(5, vector<char>(5));

vector<pair<int, int>> dyx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 동서남북
// vector<pair<int, int>> dyx2 = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}; 

bool check(int y, int x){
    // 직선
    for(int i = 0; i < 4; i++){
        int ny = y + dyx[i].first; 
        int nx = x + dyx[i].second;
        if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue; 
        if(area[ny][nx] == 'X') continue; // 파티션이면 continue!!
        if(area[ny][nx] == 'P') return false;
        
        // 한 번 더 직선으로 이동
        int nny = ny + dyx[i].first; 
        int nnx = nx + dyx[i].second;
        if(nny < 0 || nnx < 0 || nny >= 5 || nnx >= 5) continue; 
        if(area[nny][nnx] == 'P') return false;
        
        // 오른쪽 이동
        int rny = ny + dyx[(i+1)%4].first;
        int rnx = nx + dyx[(i+1)%4].second;
        if(rny < 0 || rnx < 0 || rny >= 5 || rnx >= 5) continue; 
        if(area[rny][rnx] == 'P') return false;
        
        // 왼쪽 이동
        int lny = ny + dyx[(i-1)%4].first;
        int lnx = nx + dyx[(i-1)%4].second;
        if(lny < 0 || lnx < 0 || lny >= 5 || lnx >= 5) continue; 
        if(area[lny][lnx] == 'P') return false;
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto& p: places){
        bool res = true;
        // 배열 만들기
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                area[i][j] = p[i][j]; 
            }
        }
        // p면 맨해튼 거리 확인하며 파티션 없으면 0 리턴
        for(int y = 0; y < 5; y++){
            if(!res) break;
            for(int x = 0; x < 5; x++){
                if(area[y][x] == 'P') 
                    if(!check(y, x)) { 
                        res = false; break;
                    }
            }
        }
        answer.push_back(res); 
    }
    
    // 각 대기실별로 거리두기를 지키고 있으면 1을, 한 명이라도 지키지 않고 있으면 0을 배열에 담아 return
    return answer;
}