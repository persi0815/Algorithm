#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define endl '\n'
using namespace std;

/*
중요도에 맞게 인쇄하는 것. 
몇 번째로 인쇄되는지 알아야 함
중요도가 같은 문서가 여러 개 있을 수도 있다.

애보다 숫자 높은건 이미 다 쳐내야 함. 
*/

int t;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n, loc;

		int res = 0;
		vector<int> num(10, 0); // 가중치 정리
		queue<int> q;

		cin >> n >> loc;

		for (int i = 0; i < n; i++) { // 큐에 넣기
			int x; cin >> x;
			q.push(x);
			num[x]++;
	
		}


		while (!q.empty()) {

			int now = q.front();
			bool flag = 1;
			for (int i = now + 1; i < 10; i++) { // 이보다 중요도 큰게 있나? 
				if (num[i] != 0) flag = 0;
			}

			if (flag == 1) { // 현재꺼가 가장 중요도가 큼 -> 빼야함
				if (loc == 0) { // 내가 원하는 것
					res++;
					break;
				}
				else { // 내가 원하는 것이 아님
					res++; num[now]--;
					q.pop(); // q.push(now);
					loc = (loc - 1 < 0) ? (loc - 1 + q.size()) : loc - 1;
				}
			}
			else { // 현재꺼가 가장 중요도가 큰게 아님
					q.pop();  q.push(now);
					loc = (loc - 1 < 0) ? (loc - 1 + q.size()) : loc - 1;
			}
		}

		cout << res << endl;
	}
}
