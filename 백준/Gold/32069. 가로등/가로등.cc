#include <iostream>
#include <vector>
using namespace std;

/*가로등
l개의 위치 중 n개의 가로등이 켜져있는데, k개의 값 출력

*/

long long L, N, K;
vector<int> loca(N);
vector<long long> dark(500010, 0);

void solution() {
	// 맨압
	for (int i = 1; i <= loca[0]; i++) {
		if (i > 500000) break;
		dark[i]++;
	}

	if (N > 1) {
		// 중간
		for (int i = 0; i <= N - 2; i++) { // 안에 짝수개
			if ((loca[i + 1] - loca[i] - 1) % 2 == 0) {
				for (int j = 1; j <= (loca[i + 1] - loca[i] - 1) / 2; j++) {
					if (j <= 500000) dark[j] += 2;
					else break;
				}
			}
			else { // 안에 홀수개
				for (int j = 1; j <= (loca[i + 1] - loca[i] - 1) / 2; j++) {
					if (j <= 500000) dark[j] += 2;
				}
				if (((loca[i + 1] - loca[i] - 1) / 2 + 1) <= 500000) dark[(loca[i + 1] - loca[i] - 1) / 2 + 1]++;
				else break;
			}
		}
	}


	// 맨뒤
	for (int i = 1; i <= L - loca[N-1]; i++) {
		if (i > 500000) break;
		dark[i]++;
	}
}

int num = 0;

void print() {

	while (K > 0) {
		if (num > 500000) break;

		if (dark[num] >= K) {
			for (int i = 0; i < K; i++) {
				cout << num << endl;
			}
			K = 0;
		}
		else if (dark[num] < K) {
			for (int i = 0; i < dark[num]; i++) {
				cout << num << endl;
			}
			K -= dark[num];
		}
		num++;
	}
}

int main() {
	// 입력
	cin >> L >> N >> K;
	loca.resize(N);
	dark[0] = N;

	for (int i = 0; i < N; i++) {
		cin >> loca[i];
	}

	// 로직
	solution();

	// 출력
	print();

	return 0;
}