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

        // 중복 조합 방식: 도시 하나 고정 → 가능한 고객 수 누적
    for (auto& city : cities) {
        for (int i = city.second; i <= C + 100; ++i) {
            if (dp[i - city.second] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - city.second] + city.first);
            }
        }
    }

    int result = *min_element(dp.begin() + C, dp.begin() + C + 101);

    cout << result << endl;
    return 0;
}
