#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int weight, u, v;
    bool operator<(const Edge& other) const { // 여기선없어도 되는데,  sort()로 정렬시 weight로 오름차순이 되도록 한다. 
        return weight < other.weight;
    }
};

vector<int> parent;

// Find 연산 (경로 압축 적용)
int find(int a) {
    if (a == parent[a]) 
        return a;
    return parent[a] = find(parent[a]);  // 경로 압축
}

// Union 연산 (작은 루트 노드 기준으로 합침)
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

    vector<Edge> edges;
    parent.resize(n + 1);

    // 부모 배열 초기화 (자기 자신을 부모로 설정)
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    // 간선 입력
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }

    // 간선 가중치 기준 정렬 (오름차순)
    sort(edges.begin(), edges.end());

    int mst_weight = 0;
    for (auto& edge : edges) {
        if (find(edge.u) != find(edge.v)) {  // 루트가 다르면 연결
            union_sets(edge.u, edge.v);
            mst_weight += edge.weight;
        }
    }

    cout << mst_weight << endl;
    return 0;
}
