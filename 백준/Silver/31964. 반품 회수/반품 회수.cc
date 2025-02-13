#include <iostream>
#include <vector>
using namespace std;

/*반품회수
트럭이 n개의 집 방문하면서 반품되는 물건 회수. 1의 속력으로 이동
멈춰서 기다릴 수도 있음
집의 위치와 반품할 물건을 내놓는 시각이 주어짐 
-> 트럭이 모든 물건 회수해서 다시 택배회사로 돌아오는 데 걸리는 시간의 최소값

지금까지 소요된 시간보다 작으면 가져갈 수 있음

*/

int n;
vector<pair<int, int>> house; // 위치, 시간

int res_time = 0;

void solution() {
	// 위치가 맨 뒤의 것 생각
	if (house[n - 1].first <= house[n - 1].second) {
		res_time += house[n - 1].second;
	}
	else {
		res_time += house[n - 1].first;
	}
	//cout << "0. 현재 위치: " << house[n - 1].first << " 도착 시간:" << res_time << endl;


	for (int i = n - 2; i >= 0; i--) {
		if ((res_time + house[i+1].first - house[i].first) < house[i].second) { // 도착하는 데에 걸리는 시간 < 내놓는데에 걸리는 시간
			res_time = house[i].second;
			//cout << "1. 현재 위치: " << house[i].first << " 도착 시간:" << res_time << endl;
		}
		else { // 도착하는 데에 걸리는 시간 >= 내놓는데에 걸리는 시간
			res_time += (house[i + 1].first - house[i].first);
			//cout << "2. 현재 위치: " << house[i].first << " 도착 시간:" << res_time << endl;
		}
	}
	res_time += house[0].first;
}

int main() {
	// 입력
	cin >> n;
	house.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> house[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> house[i].second;
	}

	// 로직
	solution();

	cout << res_time;

	return 0;
}