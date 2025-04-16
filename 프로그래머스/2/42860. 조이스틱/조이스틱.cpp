#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int move = len - 1;

    for (int i = 0; i < len; i++) {
        // 상하 조작
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        // 좌우 이동 최적화
        int next = i + 1;
        while (next < len && name[next] == 'A') next++;

        move = min(move, i + i + (len - next)); // 우회
        move = min(move, i + 2 * (len - next)); // 반대로 돌기
    }

    answer += move;
    return answer;
}
