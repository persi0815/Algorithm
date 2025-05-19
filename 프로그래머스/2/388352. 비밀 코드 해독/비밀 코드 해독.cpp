#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans_cnt = 0;

int match_count(const vector<int>& code, const vector<int>& guess) {
    int cnt = 0;
    for (int num : guess) {
        if (find(code.begin(), code.end(), num) != code.end()) {
            cnt++;
        }
    }
    return cnt;
}

void recursion(int start, vector<int>& code, int n,
               const vector<vector<int>>& q, const vector<pair<int, int>>& reply) {
    if (code.size() == 5) {
        for (const auto& [expected, idx] : reply) {
            if (match_count(code, q[idx]) != expected) return;
        }
        ans_cnt++;
        return;
    }

    for (int i = start; i <= n; i++) {
        code.push_back(i);
        recursion(i + 1, code, n, q, reply);
        code.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    ans_cnt = 0;
    vector<pair<int, int>> reply;
    for (int i = 0; i < q.size(); i++) {
        reply.emplace_back(ans[i], i);
    }

    vector<int> code;
    recursion(1, code, n, q, reply);
    return ans_cnt;
}
