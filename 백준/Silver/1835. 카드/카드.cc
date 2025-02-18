
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#define endl '\n'

using namespace std;

/*
1~n까지 숫자가 적힌 카드가 있음. 카드로 마술
맨 앞의 카드를 1번 뒤로 옮기고 1나오고 2번 뒤로 옮기고 2나오고 등.. n번 카드만 남을때까지 반복
-> 마리 카드의 순서를 알고 있어야 함!!
카드의 개수 n이 주어져 있을때 카드의 초기 순서를 구하는 프로그램? 

1부터 1000까지의 합이 500500
*/

int n;
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = n; i >= 1; i--) {
		dq.push_front(i);

		for (int j = 0; j < i; j++) { 
			int b = dq.back();
			dq.pop_back(); dq.push_front(b);
		}
	}

	// 출력
	for (int num : dq) {
		cout << num << " ";
	}
	
	
}