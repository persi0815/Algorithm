#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/* 인구 이동 (DFS 기반 풀이) */

int n, l, r;
vector<vector<int>> a;
vector<pair<int, int>> dyx = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<bool>> visited;

// DFS를 사용하여 연합 찾기
void dfs(int y, int x, vector<pair<int, int>> &union_countries, int &total_population) {
    visited[y][x] = true;
    union_countries.push_back({y, x});
    total_population += a[y][x];

    for (const auto &dir : dyx) {
        int n_y = y + dir.first;
        int n_x = x + dir.second;

        if (n_y < 0 || n_y >= n || n_x < 0 || n_x >= n) continue;
        if (visited[n_y][n_x]) continue;

        int diff = abs(a[y][x] - a[n_y][n_x]);
        if (diff >= l && diff <= r) {
            dfs(n_y, n_x, union_countries, total_population);
        }
    }
}

int main() {
    cin >> n >> l >> r;
    a.resize(n, vector<int>(n));

    // 인구수 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int day = 0;
    while (true) {
        visited.assign(n, vector<bool>(n, false));
        bool flag = false; // 인구 이동 발생 여부

        // 모든 국가를 순회하면서 연합 찾기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    vector<pair<int, int>> union_countries;
                    int total_population = 0;

                    dfs(i, j, union_countries, total_population);

                    // 연합에 속한 나라가 2개 이상이면 인구 이동 발생
                    if (union_countries.size() > 1) {
                        flag = true;
                        int avg_population = total_population / union_countries.size();

                        // 연합 내 국가들에 평균 인구 적용
                        for (const auto &country : union_countries) {
                            a[country.first][country.second] = avg_population;
                        }
                    }
                }
            }
        }

        if (!flag) break; // 더 이상 인구 이동이 발생하지 않으면 종료
        day++;
    }

    cout << day;
}
