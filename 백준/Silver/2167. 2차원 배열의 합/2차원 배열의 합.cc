#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> prefix_sum(N + 1, vector<int>(M + 1, 0));

    // 배열 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
        }
    }

    // 2차원 누적 합 배열 계산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            prefix_sum[i][j] = A[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }

    // 쿼리 처리
    int Q;
    cin >> Q;
    while (Q--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;

        int result = prefix_sum[x][y] - prefix_sum[i - 1][y] - prefix_sum[x][j - 1] + prefix_sum[i - 1][j - 1];
        cout << result << '\n';
    }

    return 0;
}
