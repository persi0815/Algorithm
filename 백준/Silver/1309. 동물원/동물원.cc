#include <iostream>
#include <vector>
using namespace std;

/* 동물원
사자들이 가로로도 세로로도 붙어있게 배치할 수 없음
2*n 배열에 사자를 배치하는 경우의 수가 몇 가지인지. 사자를 한마리도 배치하지 않을 수도 있음
맨윗줄에 아무것도 없기/왼쪽에 하나 있기/오른쪽에 하나 있기
*/
#define MOD 9901
int dp[100001][3] = { 0 };
int n;

int main() {

    cin >> n;

    dp[1][0] = dp[1][1] = dp[1][2] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << '\n';

    return 0;
}