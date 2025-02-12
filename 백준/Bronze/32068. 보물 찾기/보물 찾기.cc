#include <iostream>
using namespace std;

/* 보물 찾기
보물 숨겨 -> s에서 찾기 시작 -> 아래 단계 순서대로 수행 (L < S < R)
몇 번째 단계에서 보물 찾기 놀이가 끝나는가
두개 중 하나만 찾으면 됨. 더 가까운거 찾으면 되겠다. 
*/

int t;
int l, r, s;

void solution() {
	while (t--) {
		cin >> l >> r >> s;
		if ((r - s) <= (s - l)) {
			cout << (r - s) * 2 << endl;
		}
		else {
			cout << ((s - l) * 2 + 1) << endl;
		}
	}

}

int main() {
	// 입력
	cin >> t;

	// 로직
	solution();
}