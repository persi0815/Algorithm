#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
/*
나이트가 n*m 체스판 가장 왼쪽 아래 칸에 위치해 있음. 
4가지로만 움직일 수 있음. 
방문한 칸의 수를 최대로 하려고 함. 방문 할 수 있는 칸의 개수중 최댓값
4번 이동했다면, 이미 4가지 방법을 모두 사용했어야 한다!!!

*/
int n, m;
int res = 0;
vector<pair<int, int>> dyx = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}};

int main(){
    cin >> n >> m;
    
    vector<vector<int>> v = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 2, 2, 3, 3, 4},
        {0, 1, 2, 3, 4, 4, 4, 5}
    };
    // 높이 3이상이면 고려 안해도 됨. 너비 8 이상이면 그냥 1씩 더해주면 됨. 
    
    if(n < 3){
        if(m <= 7) res = v[n][m];
        else res = v[n][7];
    }else{
        if(m <= 7) res = v[3][m]; 
        else res = v[3][7] + m - 7; 
    }
    
    cout << res;

}

