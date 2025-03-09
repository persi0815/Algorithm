#include <iostream>

using namespace std;

int N, R, C;
int turn = 0;

void divideAndConquer(int x, int y, int size) {
    // 목표 위치에 도달한 경우 결과 출력 후 종료
    if (y == R && x == C) {
        cout << turn << endl;
        exit(0); // 프로그램 종료
    }

    // 더 이상 분할할 수 없는 최소 단위
    if (size == 1) {
        turn++;
        return;
    }

    // 현재 사각형 영역에 목표 좌표가 없는 경우, 해당 영역을 모두 방문한 것으로 처리
    if (!(y <= R && R < y + size && x <= C && C < x + size)) {
        turn += size * size;
        return;
    }

    // 4등분하여 재귀 호출 (Z 모양 순서: 좌상 → 우상 → 좌하 → 우하)
    int half = size / 2;
    divideAndConquer(x, y, half);
    divideAndConquer(x + half, y, half);
    divideAndConquer(x, y + half, half);
    divideAndConquer(x + half, y + half, half);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 받기
    cin >> N >> R >> C;

    // 분할 정복 시작
    divideAndConquer(0, 0, 1 << N); // 2^N = 1 << N

    return 0;
}
