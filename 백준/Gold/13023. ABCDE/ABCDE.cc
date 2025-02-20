#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* abcde
n명이 참가하고 있음. 0~n-1번으로 번호가 매겨져 있고, 일부 사람들은 칭구
다음과 같은 친구 관계를 가진 사람 a, b, c, d, e가 존재하는지 구해보려 함!
a-b-c-d-e
*/

int n, m;
vector<int> friends[2001];
vector<bool> visited(2001, 0);
bool flag = 0;

void dfs(int a, int num) {
	if (flag) return;

	if (num == 5) {
		flag = 1;
		return;
	}

	for (int i = 0; i < friends[a].size(); i++) {
		if (visited[friends[a][i]] == 0) {
			visited[friends[a][i]] = 1;
			dfs(friends[a][i], num+1);
			visited[friends[a][i]] = 0; 
		}
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		visited[i] = 1;
		dfs(i, 1);
		visited[i] = 0;

		if (flag) break;
	}

	if (flag) cout << 1;
	else cout << 0;
}