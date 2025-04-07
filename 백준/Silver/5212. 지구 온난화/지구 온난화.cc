#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
/* 지구 온난화
지구온난화 -> 남해의 지도는 어떻게 바뀔까? 
r*c 크기의 그리드로 나타낼 수 있다. X = 땅, . = 바다
50년 지나면 인접한 세칸 또는 네칸에 바다가 있느 땅은 모두 잠겨버린다. 
50년 후 지도를 그려보자. 
지도의 크기는 모든 섬을 포함하는 가장 작은 직사각형
섬은 적어도 한개 있다. 

영향이 전파가 되면 안되기에 일단 바뀌어야 할 곳은 따로 표시
*/

int r, c; // 지도의 크기
vector<pair<int, int>> dyx = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
int main(){
    cin >> r >> c; 
    vector<vector<char>> v(r, vector<char>(c)); 
    vector<pair<pair<int, int>, bool>> x; // {{y, x}, 잠긴다}
    
    for(int i = 0; i < r; i++){
        string str; cin >> str;
        for(int j = 0; j < c; j++){
            v[i][j] = str[j];
            if(v[i][j] == 'X') x.push_back({{i, j}, false}); 
        }
    }
    
    
    // 50년 후
    for(auto& xx : x){
        int c_y = xx.first.first;
        int c_x = xx.first.second;
        int cnt = 0;
        for(int i = 0; i < 4; i++){
            int n_y = c_y + dyx[i].first; 
            int n_x = c_x + dyx[i].second; 
            if(n_y < 0 || n_y >= r || n_x < 0 || n_x >= c || v[n_y][n_x] == '.') cnt++;
            if(cnt >= 3) {
                xx.second = true;
            }
        }
    }
    
    // 지도 영역 찾기 & 갱신
    int up = r, down = -1, left = c, right = -1;
    for(auto& xx : x){
        if(xx.second == false){
            if(up > xx.first.first) up = xx.first.first;
            if(down < xx.first.first) down = xx.first.first;
            if(left > xx.first.second) left = xx.first.second;
            if(right < xx.first.second) right = xx.first.second;
        }
        else if(xx.second == true){ 
            v[xx.first.first][xx.first.second] = '.';
        }
    }
    //cout << up << " " << down << " " << left << " " << right << endl;
    
    
    // 지도 출력. 가장 작은 직사각형
    for(int i = up; i <= down; i++){
        for(int j = left; j <= right; j++){
            cout << v[i][j];
        }
        cout << '\n';
    }
    
    
}