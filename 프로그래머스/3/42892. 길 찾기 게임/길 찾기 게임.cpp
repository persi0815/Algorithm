#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 전위 순회
void preOrder(int node, vector<pair<int, int>>& adj, vector<int>& res) {
    if (node == 0) return;
    res.push_back(node);
    preOrder(adj[node].first, adj, res);
    preOrder(adj[node].second, adj, res);
}

// 후위 순회
void postOrder(int node, vector<pair<int, int>>& adj, vector<int>& res) {
    if (node == 0) return;
    postOrder(adj[node].first, adj, res);
    postOrder(adj[node].second, adj, res);
    res.push_back(node);
}

// nodes: [x, y, id] 형태의 리스트 (Y 내림차순 정렬됨)
// startIdx: 현재 탐색을 시작할 nodes의 인덱스
// minX, maxX: 현재 노드가 가질 수 있는 x좌표의 범위
int makeTree(vector<vector<int>>& nodes, 
             vector<pair<int, int>>& adj, 
             int startIdx, int minX, int maxX) {
    
    if (startIdx >= nodes.size()) return 0;

    // 현재 범위 내에서 가장 높은(Y값이 큰) 노드를 찾음
    int currNodeIdx = -1;
    for (int i = startIdx; i < nodes.size(); i++) {
        if (nodes[i][0] > minX && nodes[i][0] < maxX) {
            currNodeIdx = i;
            break;
        }
    }
    // 범위 내에 노드가 없으면 자식이 없는 것
    if (currNodeIdx == -1) return 0;

    int currX = nodes[currNodeIdx][0];
    int currId = nodes[currNodeIdx][2];

    // 부모의 x값(currX)을 기준으로 범위를 쪼개서 자식을 찾음 (재귀)
    // 왼쪽 자식: (minX ~ currX) 범위에서 찾음
    adj[currId].first = makeTree(nodes, adj, currNodeIdx + 1, minX, currX);
    
    // 오른쪽 자식: (currX ~ maxX) 범위에서 찾음
    adj[currId].second = makeTree(nodes, adj, currNodeIdx + 1, currX, maxX);

    return currId; // 찾은 노드 번호를 부모에게 반환
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int n = nodeinfo.size();
    vector<vector<int>> nodes; // {x, y, id}
    for (int i = 0; i < n; i++) {
        nodes.push_back({nodeinfo[i][0], nodeinfo[i][1], i + 1});
    }

    // 1. Y기준 내림차순(높은 순), X기준 오름차순 정렬
    sort(nodes.begin(), nodes.end(), [](vector<int>& a, vector<int>& b) {
        if (a[1] != b[1]) return a[1] > b[1];
        return a[0] < b[0];
    });

    vector<pair<int, int>> adj(n + 1, {0, 0});

    // 2. 트리 구성 (전체 범위 -1 ~ 100,001 설정)
    int rootNode = makeTree(nodes, adj, 0, -1, 100001);

    // 3. 순회 결과 생성
    vector<int> pre, post;
    preOrder(rootNode, adj, pre);
    postOrder(rootNode, adj, post);

    return {pre, post};
}