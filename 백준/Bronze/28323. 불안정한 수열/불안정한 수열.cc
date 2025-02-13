#include <iostream>
#include <vector>
using namespace std;

/* 불안정한 수열
수들 중 몇개(최소 1개)의 자연수를 원하는 만큼 고를 수 있다. 
고른 자연수들의 순서는 기존에 놓여있던 순서 그대로 유지된다. 
이웃한 자연수의 합을 구했을때, 항상 홀수 = 홀짝 반복 -> 불안정한 수열!
가장 긴 불안전한 수열의 길이? 
*/

int n;
vector<int> arr(n);
bool type;
int length = 0;

void solution() {
	if (arr[0] % 2 == 0) type = 0; 
	else type = 1;
	length++;

	if (n <= 1) return;

	for (int i = 1; i < n; i++) {
		if (arr[i] % 2 == 0 && type == 1) {
			type = 0;
			length++;
		}
		else if (arr[i] % 2 == 1 && type == 0) {
			type = 1;
			length++;
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

	cout << length;

	return 0;
}