#include <iostream>
#include <vector>
using namespace std;

/* 호숫가의 개미굴
각 통로가 직접 연결하는 두 곳 중 최대 한 곳에만 살도록
살 수 있는 최대한 많은 수의 개미들의 수?
일단 쪽방에 다 밀어놓고, 중간중간 남은 방들의 개수 이용하면 됨. 

아 첫방이랑 마지막 방이랑 연결되어있다는거 까먹었... 
*/

int n;
vector<long long> room;
int z_cnt = 0;
long long cnt = 0;
bool first_flag = 0;
bool first_time_cnt = 0;

void update() {
	if (z_cnt % 2 == 0) {
		cnt += (z_cnt / 2);
	}
	else {
		cnt += (z_cnt / 2 + 1);
	}
	if (first_time_cnt == 0) first_time_cnt = z_cnt;
	//cout << cnt << " " << z_cnt << endl;
	z_cnt = 0;
}

void solution() {
	// 쪽방이 있었던 곳은 살지 못함. 중간중간 0이 연속으로 몇개있는지 판별
	// 짝수개면 /2
	// 홀수개면 /2 + 1
	if (room[0] == 1) first_flag = 1;

	for (int i = 0; i < n; i++) {
		if (room[i] == 0) {
			z_cnt++;
			if (i == n - 1) {
				if (first_flag == 1 && first_time_cnt % 2 == 1 && z_cnt % 2 == 1) {
					cnt += (z_cnt / 2);
				}
				else if (first_flag == 0 && first_time_cnt == 0 && z_cnt % 2 == 1) {
					cnt += (z_cnt / 2);
				}
				else update();
			}
		}

		else if (i != 0) {
			update();
		}
	}

}

int main() {

	// 입력
	cin >> n;
	room.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> room[i];
		cnt += room[i]; // 일단 쪽방에는 다 넣어놔
	}

	// 로직
	solution();

	cout << cnt;

	return 0;
}
