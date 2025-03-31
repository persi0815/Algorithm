#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;

    vector<pair<int, int>> cities(N); // {cost, customer}
    for (int i = 0; i < N; ++i) {
        cin >> cities[i].first >> cities[i].second;
    }

    // dp[i]: i명의 고객을 얻는 최소 비용
    vector<int> dp(C + 101, INT_MAX); // 여유 공간을 좀 줘야 함
    dp[0] = 0;

    for (int i = 0; i <= C; ++i) {
        if (dp[i] == INT_MAX) continue;
        for (auto& city : cities) { // 도시 순서는 상관 없음
            int next_customer = i + city.second;
            int next_cost = dp[i] + city.first;
            if (dp[next_customer] > next_cost) {
                dp[next_customer] = next_cost;
            }
        }
    }

    int result = INT_MAX;
    for (int i = C; i <= C + 100; ++i) {
        result = min(result, dp[i]);
    }

    cout << result << endl;
    return 0;
}
