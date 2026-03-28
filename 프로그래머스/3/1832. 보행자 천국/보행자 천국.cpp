#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city) {
    int answer = 0;
    
    vector<vector<int>> right(m, vector<int>(n, 0)); // 좌 -> 우
    vector<vector<int>> down(m, vector<int>(n, 0)); // 북 -> 남
    right[0][0] = 1; down[0][0] = 1; 
    
    bool r_flag = true; bool d_flag = true;
    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++){
            if(y == 0 && x == 0) continue;
            
            if(y == 0 && city[y][x] != 1 && r_flag) {right[y][x] = 1; continue; }
            if(x == 0 && city[y][x] != 1 && d_flag) {down[y][x] = 1; continue; }
            if(y == 0 && city[y][x] == 1) {r_flag = false; continue; }
            if(x == 0 && city[y][x] == 1) {d_flag = false; continue; }
            if(y == 0 || x == 0) continue;
            
            
            if(city[y][x] == 1) continue; 
            
            // 왼쪽에서 오는 값
            if(city[y][x-1] == 2){
                right[y][x] = right[y][x-1];
            }else if(city[y][x-1] == 0){
                right[y][x] = (right[y][x-1] + down[y][x-1])% MOD;
            }
            
            // 위쪽에서 오는 값
            if(city[y-1][x] == 2){
                down[y][x] = down[y-1][x];
            }else if(city[y-1][x] == 0){
                down[y][x] = (down[y-1][x] + right[y-1][x]) % MOD;
            }
            
        }
    }
    
 
    
    answer = (right[m-1][n-1] + down[m-1][n-1]) % MOD;
    return answer; // 자동차로 이동 가능한 전체 가능한 경로 수
}