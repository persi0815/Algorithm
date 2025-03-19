#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> classroom;
unordered_map<int, vector<int>> student_likes;
unordered_map<int, pair<int, int>> student_positions;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 자리 배정 함수
void place_students(const vector<int>& order) {
    for (int student : order) {
        priority_queue<tuple<int, int, int, int>> pq; 

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] != 0) continue; // 이미 배정된 자리 건너뜀

                int liked_count = 0, empty_count = 0;

                for (auto dir : directions) {
                    int nr = r + dir.first, nc = c + dir.second;
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                    if (classroom[nr][nc] == 0) empty_count++;
                    else if (find(student_likes[student].begin(), student_likes[student].end(), classroom[nr][nc]) 
                             != student_likes[student].end()) {
                        liked_count++;
                    }
                }

                // 우선순위 큐 (좋아하는 학생 수, 빈칸 수, 행, 열) 기준 정렬
                pq.push(make_tuple(liked_count, empty_count, -r, -c));
            }
        }

        // 가장 적합한 자리 선택
        tuple<int, int, int, int> top_element = pq.top();
        int row = -get<2>(top_element), col = -get<3>(top_element);

        // 자리 배정
        classroom[row][col] = student;
        student_positions[student] = {row, col};
    }
}

// 만족도 계산 함수
int calculate_satisfaction() {
    int score = 0;
    vector<int> satisfaction_score = {0, 1, 10, 100, 1000};

    for (const auto& kv : student_positions) {
        int student = kv.first;
        int r = kv.second.first, c = kv.second.second;
        int liked_count = 0;

        for (auto dir : directions) {
            int nr = r + dir.first, nc = c + dir.second;
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

            if (find(student_likes[student].begin(), student_likes[student].end(), classroom[nr][nc]) 
                != student_likes[student].end()) {
                liked_count++;
            }
        }

        score += satisfaction_score[liked_count];
    }

    return score;
}

int main() {
    cin >> n;
    classroom.assign(n, vector<int>(n, 0));

    vector<int> order;
    for (int i = 0; i < n * n; i++) {
        int student, a, b, c, d;
        cin >> student >> a >> b >> c >> d;
        student_likes[student] = {a, b, c, d};
        order.push_back(student);
    }

    place_students(order);
    cout << calculate_satisfaction() << endl;

    return 0;
}
