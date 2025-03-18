#include <string>
#include <vector>
#include <iostream> 
using namespace std;
/*
(n, n)으로 이동시키자! 이동시킬 수 없는 경우 0 출력
이동시키는 방법의 개수는? 
dfs? 해보자 bfs?
*/

int n;
int way = 0; 
vector<vector<int>> arr;

void move(pair<pair<int, int>, pair<int, int>> now, int loc){
    int fy = now.first.first, fx = now.first.second;
    int sy = now.second.first, sx = now.second.second;
    
    if(sx == n && sy == n){ // 도착했어
        way++;
        return;
    }
    
    // 대각선으로
    if(sx + 1 <= n && sy + 1 <= n){
        if(arr[sy+1][sx] == 0 && arr[sy][sx+1] == 0 && arr[sy+1][sx+1] == 0)
            move({{sy, sx},{sy+1, sx+1}}, 2);
    }
        
    // 가로로 (세로인 경우 불가)
    if(sx + 1 <= n && loc != 1){
        if(arr[sy][sx+1] == 0){
            move({{sy, sx}, {sy, sx+1}}, 0);
        }
    }
    
    // 세로로 (가로인 경우 불가)
    if(sy + 1 <= n && loc != 0){
        if(arr[sy+1][sx] == 0){
            move({{sy, sx}, {sy+1, sx}}, 1);
        }
    }
    
}

void sol(vector<vector<int>> &arr){
    // 매개변수: 현재 위치(이중 pair), 
    pair<pair<int, int>, pair<int, int>> now = {{1,1},{1,2}};
    
    move(now, 0);
}

int main(){
    cin >> n;
    arr.resize(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++){ // 빈칸0, 벽1
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    
    // 가로 혹은 세로, 대각선으로 이동시키는데, 벽이 있으면 갈 수 없어. 
    // 갈때마다 가능한지 확인하고 가자. 벽인지, 경계인지
    // 파이프 끝과 끝 저장하면 될 듯
    
    sol(arr);
    cout << way;
    
    
}





