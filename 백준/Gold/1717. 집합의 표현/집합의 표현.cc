#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; // 부모 노드 저장 배열

// Find 연산 (경로 압축 적용)
int find(int target) {
    if (target == parent[target]) 
        return target;
    return parent[target] = find(parent[target]);  // 경로 압축
}

// Union 연산 (작은 루트 노드 기준으로 합치기)
void union_sets(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;  // 이미 같은 집합이면 합칠 필요 없음

    if (a < b) 
        parent[b] = a;  // 작은 루트를 기준으로 합침
    else 
        parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // 부모 배열 초기화 (자기 자신을 부모로 설정)
    parent.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int x, a, b;
        cin >> x >> a >> b;

        if (x == 0) {
            union_sets(a, b);  // 합집합 연산
        } else {
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
