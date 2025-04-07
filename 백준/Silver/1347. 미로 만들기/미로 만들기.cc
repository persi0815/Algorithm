#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
/*
남쪽 보며 서있음
미로는 직사각형 격자. 이동 가능하거나 못함(벽)
적어도 하나의 이동할 수 있는 칸 존재. 
이동 가능한 칸 모두 이동해봄. 자신의 움직임 기록. 못 간 곳은 벽임. 
시작 좌표를 (0, 0)? -> 움직인 곳 . 으로 표시. -> 직사각형 확인해서 못 간 곳 #으로 출력
*/

int len; // 50
vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
vector<vector<char>> v(110, vector<char>(110, '#'));
// r방향으로 남-서-북-동
int main(){
    cin >> len; 
    string str; cin >> str;

    // 경계
    int up = 50; int down = 50; 
    int right = 50 ; int left = 50; 
    int y = 50; int x = 50; int d = 0; // 현재 위치, 방향
    v[50][50] = '.';
    
    for(int i = 0; i < len; i++){
        char order = str[i]; 
        
        if(order == 'F'){
            y = y + dir[d].first;
            x = x + dir[d].second;
            v[y][x] = '.';
            //cout << v[y][x] << endl;

            if(y < up) up = y;
            else if(y > down) down = y; 
            if(x > right) right = x;
            else if(x < left) left = x;
        }
        else{
            if(order == 'R'){
                d = (d+1) % 4;
                //cout << "dir: " << d << endl;
            }else{
                d = (d-1+4) % 4;
                //cout << "dir: " << d << endl;
            }
        }
    }

    //cout << up << " " << down << " " << right << " " << left << endl;

    // 출력
    for(int i = up; i <= down; i++){
        for(int j = left; j <= right; j++){
            cout << v[i][j];
        }
        cout << '\n';
    }
    
    
}

