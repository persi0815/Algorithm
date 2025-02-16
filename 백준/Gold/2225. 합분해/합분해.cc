#include <iostream>
using namespace std;

const int MOD = 1e9;
int dp[201][201]; // dp[N][K] -> 합이 N이 되는 K개의 수를 선택하는 방법의 수

int main() {
    int N, K;
    cin >> N >> K;

    // 초기 조건
    for (int i = 0; i <= N; i++) dp[i][1] = 1; // K=1일 때는 한 가지 방법만 존재
    for (int k = 1; k <= K; k++) dp[0][k] = 1; // N=0일 때는 모든 K에 대해 한 가지 방법 (모두 0을 선택하는 경우)

    // DP 계산
    for (int k = 2; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            if (n == 0) dp[n][k] = dp[n][k - 1] % MOD; // n이 0일 경우
            else dp[n][k] = (dp[n - 1][k] + dp[n][k - 1]) % MOD;
        }
    }

    cout << dp[N][K] << '\n';
    return 0;
}
