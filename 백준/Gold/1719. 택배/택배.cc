#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = 1e9;
int n, m;

int main() {
    cin >> n >> m;

    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    vector<vector<int>> first(n+1, vector<int>(n+1, -1));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0; // 자기자신 거리는 0
    }

    for (int i = 0; i < m; i++) {
        int a, b, c; 
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
        first[a][b] = b;
        first[b][a] = a;
    }

    // 플로이드 워셜 알고리즘
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    first[i][j] = first[i][k];
                }
            }
        }
    }

    // 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << '-' << " ";
            else cout << first[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
