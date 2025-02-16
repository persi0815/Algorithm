#include <iostream>
#include <queue>
using namespace std;

/* 숨바꼭질
수빈이는 N, 동생은 K에 위치. 
수빈이의 위치가 x일때 걷는다면 1초 후에 한칸을 움직일 수 있음
순간 이동시 2*x로 이동

수빈이가 동생을 찾을 수 있는 가장 빠른 시간은? 
*/

int n, k;
int dx[] = { -1, 1, 2 };
int dp[100001];

// 백 트래킹? dp? 
void solution() {
	queue<pair<int, int>> q; // 위치, 소요된 시간

	q.push({n, 0});
	dp[n] = 0;

	while (!q.empty()) {
		int now = q.front().first;
		int t = q.front().second;
		q.pop();

		for (int i = 0; i < 3; i++) {
			int next;
			if (i == 2) {
				next = now * 2;
			}
			else {
				next = now + dx[i];

			}

			if (next < 0 || next > 100000) continue;

			if (dp[next] == 100001) {  // 처음 방문하는 경우
				dp[next] = t + 1;
				q.push({ next, t + 1 });
			}
		}

	}
}

int main() {
	// 입력
	cin >> n >> k;
	fill(dp, dp + 100001, 100001);

	// 로직
	solution();

	cout << dp[k];

	return 0;
}