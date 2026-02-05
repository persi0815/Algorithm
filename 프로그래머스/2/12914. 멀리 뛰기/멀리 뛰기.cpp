#include <string>
#include <vector>

using namespace std;

long long solution(int n) { // 칸 수
    long long answer = 0;
    
    vector<int> dp(n+1, 0);
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }

    // 끝에 도달하는 방법의 가짓수 1234567를 나눈 나머지
    return dp[n]; 
}