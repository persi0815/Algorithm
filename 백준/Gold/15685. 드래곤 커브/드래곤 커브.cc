#include <iostream>
#include <vector>
using namespace std;
/*
드래곤 커브
1*1 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수? 
지나가는 꼭짓점에 표시
방향이 중요!!!
*/

// 동북서남 순서
vector<pair<int, int>> dyx = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int arr[101][101]; // 격자

int main() {
    int n;
    cin >> n;

    while (n--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> dir;
        arr[y][x] = 1;

        // 0세대
        int nx = x + dyx[d].second;
        int ny = y + dyx[d].first;
        arr[ny][nx] = 1;
        dir.push_back(d); // 방향을 입력

        // 1세대부터 g세대까지
        for (int gen = 1; gen <= g; gen++) {
            int sz = dir.size();
            for (int i = sz - 1; i >= 0; i--) {
                int nd = (dir[i] + 1) % 4;
                nx += dyx[nd].second;
                ny += dyx[nd].first;
                arr[ny][nx] = 1;
                dir.push_back(nd);
            }
        }

    }

    // 정사각형 개수 세기
    int cnt = 0;
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            if (arr[y][x] && arr[y][x + 1] && arr[y + 1][x] && arr[y + 1][x + 1])
                cnt++;
        }
    }

    cout << cnt;
}
