#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;


/*
듣도 보도 못한 사람의 명단 구하기

*/

int n, m;
unordered_set<string> li;
vector<string> res;
int cnt = 0;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		li.insert(str);
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (li.find(str) != li.end()) {
			cnt++;
			res.push_back(str);
		}
	}

	sort(res.begin(), res.end());
	// 두 리스트에서 중복되는 사람이 있는가? 이건거 같은데

	cout << cnt << endl;
	for (string name : res) {
		cout << name << endl;
	}
}