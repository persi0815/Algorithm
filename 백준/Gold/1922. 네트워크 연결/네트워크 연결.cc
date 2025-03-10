#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

// Find 연산 (경로 압축 적용)
int find(int a) {
    if (a == parent[a]) 
        return a;
    return parent[a] = find(parent[a]);  // 경로 압축
}

// Union 연산 (작은 루트 기준으로 합치기)
void union_sets(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;  // {가중치, {정점1, 정점2}}
    parent.resize(n + 1);

    // 부모 배열 초기화 (자기 자신을 부모로 설정)
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    // 간선 입력
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});  // {가중치, {a, b}} 형식으로 저장
    }

    // 간선 가중치 기준 정렬 (오름차순)
    sort(edges.begin(), edges.end());

    int mst_weight = 0;
    for (auto& edge : edges) {
        int weight = edge.first;
        int a = edge.second.first;
        int b = edge.second.second;

        if (find(a) != find(b)) {  // 사이클이 생기지 않는다면 연결
            union_sets(a, b);
            mst_weight += weight;
        }
    }

    cout << mst_weight << endl;
    return 0;
}
