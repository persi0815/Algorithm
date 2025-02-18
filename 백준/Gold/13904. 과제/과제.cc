
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'

using namespace std;

/*
과제마다 마감일이 있어 모든 과제를 끝내지 못할 수도 있다. 
하루에 한 과제 끝낼 수 있음

과제마다 끝냈을 때 얻는 점수가 있음
마감일이 지난 과제는 점수를 받을 수 없음

가장 점수를 많이 받을 수 있도록 과제를 수행하고 싶음. 
점수의 최댓값을 구하자

총합이 최대가 되어야 한다. 거꾸로!!!
*/

int n;
int sum = 0;
vector<pair<int, int>> work;
int longest = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, w; cin >> d >> w; // 남은 일수, 과제의 점수
		work.push_back({ d, w });
		if (longest < d) longest = d;
	}

	sort(work.begin(), work.end(), greater<>()); // 남은 기간으로 내림차순 정렬
	int idx = 0;
	priority_queue<int> score;

	// 남은 일수 차례대로 우선순위 큐에 넣으면서 하루 당 하루씩 점수 갱신
	for (int i = longest; i >= 1; i--) {

		while(idx < n && work[idx].first >= i) { // 가능한거 다 넣어
			score.push(work[idx].second);
			idx++; // 겹치지 않게
		}

		if (!score.empty()) {
			sum += score.top();
			score.pop();
		}
	}

	cout << sum;
	
}