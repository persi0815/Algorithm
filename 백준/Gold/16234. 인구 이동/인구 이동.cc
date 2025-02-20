#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

/*인구 이동
각각의 땅에는 나라가 하나씩 존재. -> a[r][c] 명이 살고 있음. 
국격선 존재. 인구 이동 시작 - 하루동안 진행. 없을때까지 지속

국경선 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하 -> 하루 동안 연다
->인구 이동 시작. 연합이라고 한다. 연합에서의 인구는 N으로 나누어짐. 소수점은 버림. 
연합 해체, 국경선 닫음

각 나라의 인구수 주어짐 -> 인구 이동이 며칠 동안 발생하는지 구하기

인구 차이가 L~R인 국경선이 언제까지 존재하는가? 를 보면 됨.  
*/

int n, l, r;
vector<vector<int>> a;
vector<pair<int, int>> dyx = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
vector<tuple<int, int, int>> uni; // 연합 번호, 총합 명수, 속한 나라 개수

bool find_union(int y, int x, vector<vector<int>> &visited, int cnt) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = cnt;

	int peo = a[y][x]; // 명수 총합
	int con = 1; // 나라 개수

	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_y = yy + dyx[i].first;
			int n_x = xx + dyx[i].second;

			if (n_y < 0 || n_y >= n || n_x < 0 || n_x >= n) continue;
			if (visited[n_y][n_x] != 0) continue;

			int diff = abs(a[yy][xx] - a[n_y][n_x]);
			if(l > diff || diff > r) continue;

			q.push({ n_y, n_x });
			visited[n_y][n_x] = cnt;
			peo += a[n_y][n_x]; 
			con++;
		}
	}

	uni.push_back({ cnt, peo, con });
	return con > 1;

	//if (con > 1) {
	//	uni.push_back({ cnt, peo, con });
	//	return true;
	//}
	//else return false;

}

int main() {
	cin >> n >> l >> r;
	a.resize(n, vector<int>(n));

	// 인구수 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int day = 0;
	while (true) {
		// 인구 차이가 L~R인 국경선이 언제까지 존재하는가? 
		// 존재한다면 -> 국경 열기 -> 어느 칸들이 하나의 연합인지 알아내야 함.
		// 존재하지 않는다면 끝 (flag로 판단)
		// 하루하루마다 visited 배열 갱신 -> 여기서 연합 1부터 작성
		// 연합 내의 국가들 개수 세면서 인구수 합 구하기 -> 또다른 visited 배열 사용
		vector<vector<int>> visited(n, vector<int>(n, 0));
		bool flag = false;
		int cnt = 1;

		// 연합 찾기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0) {
					if(find_union(i, j, visited, cnt++)) flag = true;
				}
			}
		}
		if (!flag) break; // 연합 없으면 종료

		// 국경선이 열렸다면 인구 이동 -> 그냥 차례대로 갱신
		//for (const auto& u : uni) {
		//	int union_num = get<0>(u);
		//	int avg_population = get<1>(u) / get<2>(u);
		//	
		//	for (int i = 0; i < n; i++) {
		//		for (int j = 0; j < n; j++) {
		//			if (visited[i][j] == union_num) {
		//				a[i][j] = avg_population;
		//			}
		//		}
		//	}
		//}

		//sort(uni.begin(), uni.end()); // 첫째 값(연합 번호)기준 오름차순 정렬
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = get<1>(uni[visited[i][j] - 1]) / get<2>(uni[visited[i][j] - 1]);
			}
		}
		
		uni.clear(); // 초기화. 날마다 새롭게 해야함. 
		day++;
	}
	cout << day;

}