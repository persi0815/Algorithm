#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 구조물 상수를 비트로 정의
const int ROOF = 1;   // 보
const int COLUMN = 2; // 기둥

// 보(Roof) 설치 조건 확인
bool can_roof(int x, int y, int n, const vector<vector<int>>& board) {
    // 1. 왼쪽 끝부분이 기둥 위
    if (y > 0 && (board[x][y - 1] & COLUMN)) return true;
    // 2. 오른쪽 끝부분이 기둥 위
    if (y > 0 && x < n && (board[x + 1][y - 1] & COLUMN)) return true;
    // 3. 양쪽 끝이 다른 보와 연결
    if (x > 0 && x < n && (board[x - 1][y] & ROOF) && (board[x + 1][y] & ROOF)) return true;
    return false;
}

// 기둥(Column) 설치 조건 확인
bool can_column(int x, int y, int n, const vector<vector<int>>& board) {
    // 1. 바닥 위
    if (y == 0) return true;
    // 2. 아래에 기둥이 있는 경우
    if (y > 0 && (board[x][y - 1] & COLUMN)) return true;
    // 3. 보의 왼쪽 끝 위
    if (board[x][y] & ROOF) return true;
    // 4. 보의 오른쪽 끝 위
    if (x > 0 && (board[x - 1][y] & ROOF)) return true;
    return false;
}

// 전체 구조물의 안정성 검사
bool is_all_safe(int n, const vector<vector<int>>& board) {
    for (int x = 0; x <= n; ++x) {
        for (int y = 0; y <= n; ++y) {
            if ((board[x][y] & ROOF) && !can_roof(x, y, n, board)) return false;
            if ((board[x][y] & COLUMN) && !can_column(x, y, n, board)) return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));

    for (const auto& frame : build_frame) {
        int x = frame[0], y = frame[1];
        int part = (frame[2] == 1) ? ROOF : COLUMN;
        int action = frame[3];

        if (action == 1) { // 설치
            board[x][y] |= part;
            if (!is_all_safe(n, board)) board[x][y] &= ~part;
        } else { // 삭제
            board[x][y] &= ~part;
            if (!is_all_safe(n, board)) board[x][y] |= part;
        }
    }

    vector<vector<int>> answer;
    for (int x = 0; x <= n; ++x) {
        for (int y = 0; y <= n; ++y) {
            // x -> y -> 기둥(0) -> 보(1)
            if (board[x][y] & COLUMN) answer.push_back({x, y, 0});
            if (board[x][y] & ROOF) answer.push_back({x, y, 1});
        }
    }

    // 문제의 최종 정렬 조건 적용
    sort(answer.begin(), answer.end());
    return answer;
}