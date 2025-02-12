#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* 두배
길이 n인 양의 정수열을 오름차순으로 만들고자 함
수열중 하나의 원소값을 2배할 수 있음. 해당 연산을 최소 횟수로 적용해서 오름차순으로 만들어야.
그냥 그리디 같당..
*/

int n;
vector<int> arr(250000);
int cnt = 0;

double log_b(double x) {
	return log(x) / log(2);
}

void solution() {
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			// 로그 사용
			double r = log_b((double)arr[i-1] / arr[i]);
			if (fmod(r, 1.0) < 1e-9) { // r이 정수로 딱 나눠 떨어질 때
				cnt += (int)r;
				arr[i] = arr[i] * pow(2, (int)r);
				//cout << r << " " << cnt << endl;
			}
			else {
				cnt += ((int)r + 1);
				arr[i] = arr[i] * pow(2, (int)r+1);
				//cout << r << " " << cnt << endl;

			}
			
		}
	}
	cout << cnt;
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

}