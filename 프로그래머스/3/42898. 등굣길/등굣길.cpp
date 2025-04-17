#include <string>
#include <vector>

using namespace std;
/*
물에 잠기지 않은 지역을 통해 학교를 가려고 함.
집: (1, 1 / 학교(m,n)
=> 오른쪽과 아래로만 움직여 집에서 학교로 갈 수 있는 최단 경로의 개수 % 1000000007
*/

// 격자의 크기. 물에 잠긴 지역의 좌표
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    const int MOD = 1000000007;
    
    // 물에 잠긴 지역 표시하여 배열 만들기
    vector<vector<int>> v(n+1, vector<int>(m+1, 0)); // 갈 수 있는 경우의 수
    
    // 식별 위해 -1로 설정
    for (auto& p : puddles) {
        v[p[1]][p[0]] = -1; // puddles는 [x,y] 형식
    }
    
    // 잠긴 곳 이전까지 1로 설정
    // for(int x = 2; x <= m; x++) {
    //     if(v[1][x] == -1) break;
    //     v[1][x] = 1;
    // }
    // for(int y = 2; y <= n; y++) {
    //     if(v[y][1] == -1) break;
    //     v[y][1] = 1;
    // }
    
    // 다시 0으로 초기화
    // for (auto& p : puddles) {
    //     v[p[1]][p[0]] = 0; // puddles는 [x,y] 형식
    // }
    
    v[1][1] = 1;
    // 갈 수 있는 경우의 수 갱신
    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= m; x++){
            if(v[y][x] == -1) {
                v[y][x] = 0; continue;
            }
            if(y == 1 && x == 1) continue;
            v[y][x] = (v[y-1][x] + v[y][x-1]) % MOD;
            // if (y > 1) v[y][x] = (v[y][x] + v[y-1][x]) % MOD;
            // if (x > 1) v[y][x] = (v[y][x] + v[y][x-1]) % MOD;
        }
    }
    
    answer = v[n][m];
    
    
    return answer;
}