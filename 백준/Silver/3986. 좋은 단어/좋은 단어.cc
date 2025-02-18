#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* 좋은 단어
A -> B가 됨. 좋은 단어 세기로 함. 
같은 글자끼리 쌍을 지음. 
교차하지 않으면서 각 글자를 정확히 한 개의 다른 위치에 있는 같은 글자와 짝 지을 수 있다면, 
좋은 단어이다. 

*/

int res = 0;
int n;

void define(string str) {
	stack<char> st;
	// 차례대로 하나씩 보면서 스택에 넣고  빼면 되잖아. 
	// top이랑 다르면 넣고, 같으면 빼고. 결국 스택에 아무것도 안남아야 좋은 단어!!
	for (char c : str) {
		if (st.empty()) st.push(c);
		else if (st.top() == c) st.pop();
		else st.push(c);
	}

	if (st.empty()) res++;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		define(str);
	}

	cout << res;
	
}