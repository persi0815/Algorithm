#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    vector<int> psum(n + 1, 0); // 누적 합 배열 (1-based index)

    // 배열 입력 & 누적 합 계산
    for (int i = 1; i <= n; i++) {
        cin >> arr[i - 1];  // 0-based index로 입력
        psum[i] = psum[i - 1] + arr[i - 1];
    }

    // 구간 합 계산
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << psum[r] - psum[l - 1] << '\n'; // 누적 합 활용
    }

    return 0;
}
