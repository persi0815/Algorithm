#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<cmath>
using namespace std;

vector<int> arr[101]; // 연결 관계 나타내는 배열
int visited[101]; // 방문 유무 나타냄
int ans = -1; // default 값

void dfs(int p, int b, int cnt) {
	visited[p] = 1;
	if (p == b) {
		ans = cnt;
		return;
	}
	for (int i = 0; i < arr[p].size(); i++) {
		if (visited[arr[p][i]] == 0) { // 중복 방지
			dfs(arr[p][i], b, cnt + 1);
		}
	}
	
}

int main(void)
{
	// 입력
	int n, m;
	cin >> n; // 전체 사람의 수
	int a, b;
	cin >> a >> b; // 촌수를 나타내야 하는 사람
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	// 로직
	dfs(a, b, 0);

	// 출력
	cout << ans;
}