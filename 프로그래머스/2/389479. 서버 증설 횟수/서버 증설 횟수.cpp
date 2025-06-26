#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;

    unordered_map<int, int> mm; // {증설 시간, 서버 개수}
    int time = 0; // 현재 시각
    int server_num = 0; // 현재 살아 있는 서버 개수

    for (int p : players) {
        // ✅ 1. 만료된 서버 제거
        for (auto it = mm.begin(); it != mm.end(); ) {
            if (time - it->first >= k) { // 서버 수명 초과
                server_num -= it->second;
                it = mm.erase(it);
            } else {
                ++it;
            }
        }

        // ✅ 2. 현재 필요한 서버 수 계산
        int required = p / m;

        if (required > server_num) {
            int to_add = required - server_num; // 필요한 추가 서버 수
            answer += to_add;
            server_num += to_add;
            mm[time] = to_add;

            cout << "시간: " << time << ", 추가 서버: " << to_add << ", 현재 서버: " << server_num << ", 누적 증설 횟수: " << answer << endl;
        }

        time++;
    }

    return answer;
}
