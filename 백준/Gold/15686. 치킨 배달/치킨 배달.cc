#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m; // 도시 크기, 선택할 치킨집 개수
vector<pair<int, int>> houses, chickens; // 집 위치, 치킨집 위치
vector<vector<int>> map; // 지도

// 두 좌표 간 맨해튼 거리 계산
int getDistance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// 선택된 치킨집 조합에 대한 도시의 총 치킨 거리 계산
int calculateChickenDistance(const vector<pair<int, int>>& selectedChickens) {
    int totalDistance = 0;
    for (const auto& house : houses) {
        int minDistance = INT_MAX;
        for (const auto& chicken : selectedChickens) {
            minDistance = min(minDistance, getDistance(house, chicken));
        }
        totalDistance += minDistance;
    }
    return totalDistance;
}

void solve() {
    vector<int> indices(chickens.size(), 0);
    fill(indices.end() - m, indices.end(), 1); // m개의 치킨집 선택을 위한 조합 초기화
    int minChickenDistance = INT_MAX;

    do {
        vector<pair<int, int>> selectedChickens;
        for (int i = 0; i < indices.size(); i++) {
            if (indices[i] == 1) {
                selectedChickens.push_back(chickens[i]);
            }
        }
        minChickenDistance = min(minChickenDistance, calculateChickenDistance(selectedChickens));
    } while (next_permutation(indices.begin(), indices.end()));

    cout << minChickenDistance << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    map.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 1) houses.push_back({ i, j });
            else if (map[i][j] == 2) chickens.push_back({ i, j });
        }
    }

    solve();
    return 0;
}
