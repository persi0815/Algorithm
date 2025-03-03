#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
bool visited[500][500] = {false};

tuple<int, int, int> normalize(int a, int b, int c) {
    int x = min({a, b, c});
    int z = max({a, b, c});
    int y = a + b + c - x - z;  // 중간값
    return {x, y, z};
}

void solution(int a, int b, int c) {
    queue<tuple<int, int, int>> q;
    
    tuple<int, int, int> start = normalize(a, b, c);
    q.push(start);
    visited[get<0>(start)][get<1>(start)] = true;
    
    while (!q.empty()) {
        auto tup = q.front();
        a = get<0>(tup); b = get<1>(tup); c = get<2>(tup);
        visited[a][b] = true;
        q.pop();

        if (a == b && b == c) {
            cout << 1;
            return;
        }

        // 새로운 상태를 만들고 검사
        tuple<int, int, int> next_states[3] = {
            normalize(a * 2, b - a, c),
            normalize(a * 2, b, c - a),
            normalize(a, b * 2, c - b)
        };

        for (const auto& state : next_states) {
            if(!visited[get<0>(state)][get<1>(state)]){
                q.push(state);
                
            }
            
        }
    }

    cout << 0;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    solution(a, b, c);
    return 0;
}
