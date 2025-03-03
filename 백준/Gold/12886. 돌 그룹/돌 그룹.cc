#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <algorithm>

using namespace std;

/* tuple을 unordered_set에서 사용하기 위한 해시 함수 */
struct tuple_hash {
    size_t operator()(const tuple<int, int, int>& t) const {
        return (size_t(get<0>(t)) * 31 * 31 + size_t(get<1>(t)) * 31 + size_t(get<2>(t)));
    }
};

unordered_set<tuple<int, int, int>, tuple_hash> s;

/* 항상 {최소, 중간, 최대} 형태로 변환 */
tuple<int, int, int> normalize(int a, int b, int c) {
    int x = min({a, b, c});
    int z = max({a, b, c});
    int y = a + b + c - x - z;  // 중간값
    return {x, y, z};
}

void solution(int a, int b, int c) {
    queue<tuple<int, int, int>> q;
    
    tuple<int, int, int> start = normalize(a, b, c);
    s.insert(start);
    q.push(start);
    
    while (!q.empty()) {
        auto tup = q.front();
        a = get<0>(tup); b = get<1>(tup); c = get<2>(tup);
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
            if (s.find(state) == s.end()) {
                s.insert(state);
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
