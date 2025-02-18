#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

/*
로그이 들어왔는ㄴ지 나갔는지 기록되어있음
있는 사람 사전 순의 역순으로 출력
*/

int n;
//unordered_map<string, int> number; // 이름과 번호 매핑
unordered_set<string> in;
vector<string> res;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		string status;
		cin >> name >> status;
		
		if (status == "enter") {
			//number[name] = i;
			in.insert(name);
		}
		
		if (status == "leave") {
			//int num = number[name];
			in.erase(name);
		}
	}

	for (string n : in) {
		res.push_back(n);
	}

	sort(res.begin(), res.end(), greater<>());

	for (string name : res) {
		cout << name << '\n';
	}
}