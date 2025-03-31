#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> coin(n);
        for (int i = 0; i < n; i++) {
            cin >> coin[i];
        }

        int m; cin >> m;

        vector<int> dp(m + 1, 0);
        dp[0] = 1; // 0원을 만드는 경우는 "아무 동전도 사용하지 않는 1가지"

        // 동전을 하나씩 고정하고 그 동전으로 만들 수 있는 금액을 늘려가며 경우의 수 누적
        for (int i = 0; i < n; i++) {
            for (int j = coin[i]; j <= m; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }

        cout << dp[m] << '\n';
    }

    return 0;
}
