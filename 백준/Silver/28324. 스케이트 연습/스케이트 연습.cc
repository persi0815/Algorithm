#include <iostream>
#include <vector>
using namespace std;

/* 스케이트 연습
도착 지점을 기준으로 1씩 증가하는 모습이 가능. 
중간에 떨어졌다면, 거기서 1씩만 오를 수 있음!!

*/

int n;
vector<int> arr(n);
long long r_sum = 0;
int num = 1; // 높일 수 있는 max

void solution() {
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] > num) {
			r_sum += num;
			num++;
		}
		else {
			r_sum += arr[i];
			num = (arr[i] + 1);
		}
	}
}

int main() {
	// 입력
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 로직
	solution();

	cout << r_sum; 

	return 0;
}