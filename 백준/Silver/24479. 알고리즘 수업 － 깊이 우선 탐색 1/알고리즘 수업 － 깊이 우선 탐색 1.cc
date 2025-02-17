#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* dfs
n개의 정점과 m개의 간선으로 구성된 무방향 그래프가 주어진다. 
정점 번호는 1~n. 간선의 가중치는 1. 
정점 r에서 시작하여 dfs로 노드를 방문할 경우 노드의 방문 순서를 출력

재귀가 깊어질 경우 스택 오버플로우 위험이 있음 -> stack 사용
*/

int n, m, r;
vector<vector<int>> arr;
vector<int> visited;
int cnt = 1;

void dfs(int start) {
	visited[start] = cnt++;
	for (int i = 0; i < arr[start].size(); i++) {
		if(visited[arr[start][i]] == 0) dfs(arr[start][i]);
	}
}

int main() {
	ios::sync_with_stdio(false); // 입출력 속도 향상
	cin.tie(0); // cout과 cin 분리로 속도 향상

	// 입력
	cin >> n >> m >> r; // 정점, 간선의 수, 시작 노드
	arr.resize(n+1);
	visited.resize(n + 1, 0);

	// 양방향 그래프 만들기
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(arr[i].begin(), arr[i].end()); // 오름차순 정렬
	}

	// 로직
	dfs(r);

	// 출력
	for (int i = 1; i <= n; i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}