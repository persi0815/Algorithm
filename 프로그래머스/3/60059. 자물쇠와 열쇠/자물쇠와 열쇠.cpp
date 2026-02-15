#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>>& key){
    // 시계 방향으로 돌리기
    vector<vector<int>> k(key.size(), vector<int>(key.size()));
    for(int y = 0; y < key.size(); y++){
        for(int x = 0; x < key.size(); x++){
            k[x][key.size()-1-y] = key[y][x];
        }
    }
    key = k;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    // 열쇠의 돌기로 자물쇠의 모든 홈 채우기. 돌기끼리 만나면 안됨
    
    vector<pair<int, int>> lockB; // 자물쇠의 홈
    for(int i = 0; i < lock.size(); i++){
        for(int j = 0; j < lock.size(); j++){
            if(lock[i][j] == 0) lockB.push_back({i, j}); 
        }
    }
    
    // 자물쇠에 홈이 하나도 없는 경우 (이미 다 채워진 상태)
    if (lockB.empty()) return true;

    
    // 확인하고 열쇠 돌리기
    for(int i = 0; i < 4; i++){ 
        if(answer) break; 
        
        vector<pair<int, int>> keyA; // 열쇠의 돌기
        for(int i = 0; i < key.size(); i++){
            for(int j = 0; j < key.size(); j++){
                if(key[i][j] == 1) keyA.push_back({i, j}); 
            }
        }
                
        // 맞는지 확인하기
        int ly = lockB[0].first; int lx = lockB[0].second; 
        int ky, kx;
        // 자물쇠의 첫 홈을 key의 각 돌기에 맞추고 나머지 확인
        for(int k = 0; k < keyA.size(); k++){
            ky = keyA[k].first; 
            kx = keyA[k].second; 
            
            int diffY = ly-ky; int diffX = lx-kx; 
        
            // key가 홈 다 채우는지 확인
            bool avail = true;
            for(int l = 1; l < lockB.size(); l++){
                int ny = lockB[l].first - diffY; 
                int nx = lockB[l].second - diffX;
                if(find(keyA.begin(), keyA.end(), make_pair(ny, nx)) == keyA.end()) {
                    avail = false; break;
                }
            }
            if(!avail) continue;
            // key 돌기가 lock 돌기와 만나지는 않는지 확인
            for(int k = 0; k < keyA.size(); k++){
                int ny = keyA[k].first + diffY;
                int nx = keyA[k].second + diffX;
                if(ny < 0 || nx < 0 || ny >= lock.size() || nx >= lock.size()) continue;
                if(lock[ny][nx] == 1) {
                    avail = false; break;
                }
            }
            if(!avail) continue;
            
            // 가능하다면 true
            answer = true; break;
        }
        
        // 열쇠 돌리기(시계 방향)
        rotate(key); 
    }
    
    // 열쇠로 자물쇠를 열수 있으면 true를, 열 수 없으면 false
    return answer;
}