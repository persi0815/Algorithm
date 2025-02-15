#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

/* 대피소
n개중 k개의 집에 대피소 설치 예정
집에서 가장 가가운 대피소로 이동할 때 가장 긴 거리가 최소가 되도록 설치
-> 대피소와 가장 멀리 떨어진 집과의 거리 구하려고 함

2차원 배열 만들어서 집 두개 간의 간격이 뭔지 정리해놓고
*/

int n, k;
vector<tuple<int, int>> house;
vector<int> num;
vector<vector<int>> dist;
vector<int> comb; // 조합 저장 배열
int res = -1;

void get_res(const vector<int> comb) {
	int longest = 0; // 집들에서 가장 가까운 대피소까지의 거리중 가장 긴 것

	// comb에 있는 집들이 대피소로 선택된 집들임!
	// 각각의 집들에서 대피소로 갈 때 가장 짧은 길들 선택
	for (int i = 0; i < n; i++) {
		int shortest_len = -1; // 각각의 집에서 가장 가까운 대피소까지의 거리
		for (int j = 0; j < k; j++) {
			int len = dist[i][comb[j]];
			if (shortest_len == -1) shortest_len = len;
			else if (shortest_len > len) shortest_len = len;
		}
		if (longest < shortest_len) longest = shortest_len;
	}
	// 결과값과 비교해서 짧은거로 갱신
	if (res == -1) res = longest;
	else if (res > longest) res = longest;

}

void combination(int start) {
	if (comb.size() == k) {
		get_res(comb);
		return;
	}

	for (int i = start; i < num.size(); i++) {
		comb.push_back(num[i]);  // 현재 원소 추가
		combination(i + 1);  // 다음 원소 선택
		comb.pop_back();  // 백트래킹
	}
}

void define_distance() {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int len_x = abs(get<0>(house[i]) - get<0>(house[j]));
			int len_y = abs(get<1>(house[i]) - get<1>(house[j]));
			dist[i][j] = len_x + len_y;
			dist[j][i] = len_x + len_y;
		}
	}
}

void solution() {
	define_distance();

	// 조합 구해서 해당 조합 사용시 거리가 최소 몇인지
	num.resize(n);
	for (int i = 0; i < n; i++) {
		num[i] = i;  // 0부터 n-1까지 저장
	}

	combination(0);

	cout << res;
}

int main() {
	// 입력
	cin >> n >> k;
	dist.resize(n, vector<int>(n, 0));


	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		house.push_back({ x, y });
	}



	// 로직
	solution();

	return 0;
}