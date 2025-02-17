#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> st;
    vector<char> ans;
    int cnt = 0;
    bool flag = true;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        while (cnt < val) {
            cnt++;
            st.push(cnt);
            ans.push_back('+');
        }

        if (!st.empty() && st.top() == val) {
            st.pop();
            ans.push_back('-');
        } else {
            flag = false;
            break;
        }
    }

    if (flag) {
        for (char c : ans) {
            cout << c << '\n';
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
