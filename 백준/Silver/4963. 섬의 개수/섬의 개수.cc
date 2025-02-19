#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
섬의 개수를 세는 프로그램
한 사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다. -> 걸어갈 수 있음
*/

int w, h;
vector<pair<int, int>> dyx = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

void numbering(vector<vector<int>> &arr, int y, int x, int num) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	arr[y][x] = num;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int n_y = y + dyx[i].first;
			int n_x = x + dyx[i].second;

			if (n_y < 0 || n_y >= h || n_x < 0 || n_x >= w) continue; // 경계 벗어나거나
			if (arr[n_y][n_x] != 1) continue; // 이미 갔던 곳이거나 바다라면 건너뛰기

			arr[n_y][n_x] = num;
			q.push({ n_y, n_x });
		}

	}


}

int main() {

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		vector<vector<int>> arr(h, vector<int>(w));

		for (int i = 0; i < h; i++) { // 지도 입력받기
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j]; // 1은 땅, 0은 바다
			}
		}

		//vector<vector<int>> visited(h, vector<int>(w)); // 섬 번호 2부터 붙이기
		int cnt = 2;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1) {
					numbering(arr, i, j, cnt++);
				}
			}
		}


		cout << cnt - 2 << endl;

		//cout << "============================" << endl;


	}

}
