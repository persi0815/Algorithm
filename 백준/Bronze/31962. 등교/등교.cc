#include <iostream>
using namespace std;

/* 등교
학교에 x 분 이내로 도착해야. n개의 버스중 하나 선택해서 탑승
가장 늦게 버스를 타고자 함. 
몇분후 출발, 몇분 소요
가장 늦게 출발하는 버스가 출발할 때까지 거리는 시간 - 없을 수도
*/

int n, x;
int res = -1;

void solution() {
	while (n--) {
		int s, t;
		cin >> s >> t;
		if ((s + t) <= x) {
			if (res < s) {
				res = s;
			}
		}
	}
	cout << res;
}

int main() {
	// 입력
	cin >> n >> x;

	// 로직
	solution();

}