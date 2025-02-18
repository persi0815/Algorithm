
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'

using namespace std;

int N, K;
pair<int, int> treasures[300001];
int bags[300001];

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int m, v;
		cin >> m >> v;

		treasures[i].first = m;
		treasures[i].second = v;
	}

	for (int i = 0; i < K; i++) {
		cin >> bags[i];
	}

	sort(treasures, treasures + N);
	sort(bags, bags + K);

	int idx = 0;
	long long answer = 0;
	priority_queue<int> pq;

	for (int i = 0; i < K; i++) {
		int curBag = bags[i];

		while (idx < N && treasures[idx].first <= curBag) {
			pq.push(treasures[idx].second);
			idx++;
		}

		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer;
}