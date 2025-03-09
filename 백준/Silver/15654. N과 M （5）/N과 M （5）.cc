#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> L, out;
vector<bool> visited;

void solve(int depth) {
    if (depth == M) {
        for (int num : out) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            out.push_back(L[i]);
            solve(depth + 1);
            out.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> N >> M;
    L.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    sort(L.begin(), L.end()); // 정렬

    solve(0);

    return 0;
}
