#include <iostream>
#include <cstring>
using namespace std;

int A, B, C;
int dp[21][21][21]; // 0~20

int w(int a, int b, int c) {

	// 범위를 벗어나는 경우 처리
	if (a <= 0 || b <= 0 || c <= 0) return 1;

	// 20보다 큰 값은 dp[20][20][20]으로 치환
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

	if (dp[a][b][c] != -1) return dp[a][b][c];

	else if (a < b && b < c) {
		return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main() {
	memset(dp, -1, sizeof(dp)); // -1로 초기화

	while (1) {
		cin >> A >> B >> C;
		if (A == -1 && B == -1 && C == -1) break;
		cout << "w(" << A << ", " << B << ", " << C << ") = " << w(A, B, C) << endl;
	}
	
}