#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

long long L, A;
int N, K;
const long long dx[] = { -1, 1 }; // 왼쪽과 오른쪽 이동
queue<pair<long long, long long>> q; // BFS 큐 (위치, 거리)
unordered_set<long long> visited; // 방문한 위치 저장 (set보다 빠름)

// 도로 범위 내에 있는지 확인
bool isPossible(long long x) {
    return 0 <= x && x <= L;
}

int main() {
    // 입력 받기
    cin >> L >> N >> K;

    // 가로등 위치 입력 후 BFS 시작
    for (int i = 0; i < N; ++i) {
        cin >> A;
        q.push({ A, 0 });
        visited.insert(A);
    }

    // BFS 수행
    while (!q.empty()) {
        long long here = q.front().first;
        long long dist = q.front().second;
        q.pop();

        // 현재 위치의 어두운 정도 출력
        cout << dist << "\n";
        --K;

        // K개를 출력했으면 종료
        if (K == 0) return 0;

        // 왼쪽, 오른쪽 탐색
        for (int i = 0; i < 2; ++i) {
            long long there = here + dx[i];

            // 범위 체크 & 방문 여부 확인
            if (isPossible(there) && visited.find(there) == visited.end()) {
                q.push({ there, dist + 1 });
                visited.insert(there);
            }
        }
    }

    return 0;
}