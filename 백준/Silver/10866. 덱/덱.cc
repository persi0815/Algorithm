#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <deque>
#define endl '\n'
using namespace std;

/*

*/

int n;
deque<int> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string order;
		cin >> order;

		if (order == "push_back") {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (order == "push_front") {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (order == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << endl;
				dq.pop_front();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (order == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << endl;
				dq.pop_back();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (order == "front") {
			if (!dq.empty()) {
				cout << dq.front() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (order == "back") {
			if (!dq.empty()) {
				cout << dq.back() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (order == "size") {
			cout << dq.size() << endl;
		}
		else if (order == "empty") {
			if (dq.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}


	}

}