#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 전역 변수 설정
int endY, endX, nn, mm;
string answer = "impossible";
bool found = false;

// 사용자 정의 dyx 벡터: d, l, r, u 순서
vector<pair<int, int>> dyx = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}; 
vector<char> d_char = {'d', 'l', 'r', 'u'};

void move(int y, int x, int k, string path) {
    if (found) return; // 이미 최적의 답(사전 순 첫 번째)을 찾았다면 즉시 종료

    // 남은 거리 계산 (Manhattan Distance)
    int dist = abs(y - endY) + abs(x - endX);
    int remain = k - path.length();

    // 남은 횟수로 도착 불가능하거나, 남은 횟수와 거리의 차가 홀수면 실패!!!
    if (remain < dist || (remain - dist) % 2 != 0) return;

    // 목적지 도착 및 종료 조건
    if (remain == 0) {
        if (y == endY && x == endX) {
            answer = path;
            found = true;
        }
        return;
    }

    // 사전 순 탐색 (d -> l -> r -> u) => 처음으로 발견한 답이 가장 빠른 문자열
    for (int i = 0; i < 4; i++) {
        int ny = y + dyx[i].first;
        int nx = x + dyx[i].second;

        if (ny >= 1 && ny <= nn && nx >= 1 && nx <= mm) {
            move(ny, nx, k, path + d_char[i]);
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    nn = n; mm = m; endY = r; endX = c;
    answer = "impossible";
    found = false;

    // 시작점에서 도착점까지의 거리 체크
    int start_dist = abs(x - r) + abs(y - c);
    if (start_dist > k || (k - start_dist) % 2 != 0) return "impossible";

    move(x, y, k, ""); // 초기 위치 x, y에서 시작

    return answer;
}