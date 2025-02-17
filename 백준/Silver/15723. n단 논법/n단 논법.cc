#include <iostream>
#include <vector>
using namespace std;

/* n단 논법
방향 그래프 - dfs -> T/F 출력
*/

int n, m;
vector<vector<int>> arr(26);
bool flag = 0;

bool dfs(int start, int end) {
	if (start == end) {
		flag = 1;
		return 1;
	}

	for (int i = 0; i < arr[start].size(); i++) {
		dfs(arr[start][i], end);
		//cout << "dfs: " << arr[start][i] << " " << end << endl;
	}

	if (flag == 1) return 1;
	else return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b; string c;
		cin >> a >> c >> b;
		arr[a - 'a'].push_back(b - 'a');
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		flag = 0;
		char a, b; string c;
		cin >> a >> c >> b;
		if (dfs(a - 'a', b - 'a')) cout << "T"<< endl;
		else cout << "F" << endl;
	}

}