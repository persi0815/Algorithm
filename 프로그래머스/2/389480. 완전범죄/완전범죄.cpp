#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
/*
- 각 물건에 대해 두 가지 선택지: A가 가져가거나 B가 가져가거나
- A의 흔적 합은 최소화해야 함.
- B의 흔적 합은 m 미만이어야 함.

그리디로 풀지 x -> 완전탐색으로!
*/

int solution(vector<vector<int>> info, int n, int m) {
    const int INF = 1e9;
    int answer = INF; 
    
    int maxB = m; int maxA = n;
    vector<vector<int>> dp(41, vector<int>(150, INF)); // 초기화
    // dp[i][j]: i번째 물건까지 고려했을 때, B의 흔적이 j일 때 A의 최소 흔적
    dp[0][0] = 0; 
    
    for(int i = 0; i < info.size(); i++){
        int traceA = info[i][0]; 
        int traceB = info[i][1];
        
        for(int j = 0; j < maxB; j++){
            if(dp[i][j] == INF) continue; 
            
            // a가 선택
            if(dp[i+1][j] > dp[i][j] + traceA && dp[i][j] + traceA < maxA){
                dp[i+1][j] = dp[i][j] + traceA;
            }

            // b가 선택
            if(j + traceB < maxB){
                dp[i+1][j+traceB] = dp[i][j];
            }
            
        }
    }
    
    answer = *min_element(dp[info.size()].begin(), dp[info.size()].end());
    

    if (answer == INF) return -1;
    return answer;
}
