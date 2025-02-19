#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
여러 색의 뿌요가 있음. 뿌요는 바닥이나 다른 뿌요가 나올 때까지 아래로 떨어진다. 
같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 같은색 뿌요들은 한꺼번에 없어짐
위에 뿌요들이 중력으로 아래로 떨어짐
다시 같은 색의 뿌요들이 4개 이상 있으면 또 터짐 -> 1연쇄씩 늘어남
터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고, 여러 그룹이 터지더라도 한번의 연쇄만 추가됨

상대의 필드가 주어졌을때 연쇄가 몇번 연속으로 일어날지 계산해주자

일단 현 상태에서 터질 수 있는거 다 터뜨리고 아래로 전부 내려

*/


char arr[12][6];
vector<pair<int, int>> dyx = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
bool flag = 0;

void bfs(int y, int x, char c) {
	//cout << "bfs: " << y << " " << x << " " << c << endl;
	int cnt = 1;
	queue<pair<int, int>> q;
	bool visited[12][6] = { 0 }; // set으로 해도 괜찮을듯? 

	q.push({ y, x });
	visited[y][x] = 1;

	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_y = yy + dyx[i].first;
			int n_x = xx + dyx[i].second;

			if (n_y < 0 || n_y >= 12 || n_x < 0 || n_x >= 6) continue; // 범위 밖

			if (arr[n_y][n_x] == c && visited[n_y][n_x] == 0) {
				cnt++;
				q.push({ n_y, n_x });
				visited[n_y][n_x] = 1;
				//cout << "push: " << n_y << " " << n_x << endl;
			}

		}
	}

	if (cnt >= 4) { // 연속된게 4개 이상(마지막에 하나 더 계산됨) -> 터뜨려
		flag = 1;

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (visited[i][j] == 1) arr[i][j] = '.';
			}
		}

		// 터진 후 파악
		/*cout << "x터진 후: ----------------------------------------" << endl;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}*/

	}
}

void make_down() {
	for (int col = 0; col < 6; col++) { // 각 열에 대해서
		for (int row = 11; row > 0; row--) { // 아래에서 위로 탐색
			if (arr[row][col] == '.') { // 현재 위치가 빈칸이라면
				// 현재 위치 위쪽을 탐색하며 가장 가까운 뿌요를 내려옴
				for (int k = row - 1; k >= 0; k--) {
					if (arr[k][col] != '.') { // 뿌요 발견
						arr[row][col] = arr[k][col]; // 아래로 내림
						arr[k][col] = '.'; // 기존 위치는 빈칸으로
						break; // 현재 칸에 내렸으면 다음 칸 탐색
					}
				}
			}
		}
	}
}

//void make_down() {
	// 중력으로 빈공간이 생겼다면 위의 내용들 내려
	//for (int i = 0; i < 6; i++) {
	//	pair<int, int> loc = { 12, 12 };
	//	for (int j = 11; j > 0; j--) { // 아래부터 보는데, 
	//		if (arr[j][i] == '.' && loc == make_pair(12, 12)) { // 아래가 빈공간이라면
	//			loc = { j, i }; //cout << "loc: " << j << " " << i << endl;
	//		}
	//		else if (arr[j][i] != '.' && loc != make_pair(12, 12)) { // 저장해뒀던 빈칸 사용
	//			arr[loc.first--][loc.second] = arr[j][i]; // 빈칸 사용
	//			//cout << "loc: " << loc.first << " " << loc.second << endl;
	//			arr[j][i] = '.'; // 빈칸이 됨

	//			if (arr[loc.first][loc.second] != '.') loc = { j, i };
	//		}
	//	}
	//}

	// 중력으로 내린 후 파악
	/*cout << "내린 후: ----------------------------------------" << endl;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/
//}

int main() {

	// 12*6 필드 입력받기
	for (int i = 0; i < 12; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 6; j++) {
			arr[i][j] = str[j];
		}
	}

	// 현 상황에서 터뜨릴 수 있는거 떠뜨리고(.으로 바꾸고) 내리고 반복하기
	int ans = 0;

	while (true) {
		// 개수 확인 -> 4개 이상이면 그때 터뜨려야.. 
		// 색마다 따로
		// 방문했다는거 기록해놔야함 -> 소문자로 기록할까

		// 4개 이상인거 찾기
		flag = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] != '.') bfs(i, j, arr[i][j]);
			}
		}

		if (flag == 0) break; // 터진게 없다. 
		else {
			ans++;
			make_down(); // 중력으로 떨어뜨리기
		}

	}

	cout << ans << endl;

}

