#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<pair<long long, long long>> points;

    // 1. 모든 직선 쌍의 교점 계산
    for (int i = 0; i < line.size(); i++) {
        for (int j = i + 1; j < line.size(); j++) {
            long long A1 = line[i][0];
            long long B1 = line[i][1];
            long long C1 = line[i][2];

            long long A2 = line[j][0];
            long long B2 = line[j][1];
            long long C2 = line[j][2];

            long long D = A1 * B2 - A2 * B1;
            if (D == 0) continue; // 평행

            long long x_num = B1 * C2 - B2 * C1;
            long long y_num = A2 * C1 - A1 * C2;

            if (x_num % D != 0 || y_num % D != 0) continue;

            long long x = x_num / D;
            long long y = y_num / D;

            points.push_back({x, y});
        }
    }

    // 2. 최소/최대 좌표
    long long minX = points[0].first, maxX = points[0].first;
    long long minY = points[0].second, maxY = points[0].second;

    for (auto &p : points) {
        minX = min(minX, p.first);
        maxX = max(maxX, p.first);
        minY = min(minY, p.second);
        maxY = max(maxY, p.second);
    }

    int width = maxX - minX + 1;
    int height = maxY - minY + 1;

    // 3. 격자 생성
    vector<string> answer(height, string(width, '.'));

    // 4. 별 찍기 (y축 반전)
    for (auto &p : points) {
        int x = p.first - minX;
        int y = maxY - p.second;
        answer[y][x] = '*';
    }

    return answer;
}
