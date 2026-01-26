#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int deliver_allowance = 0; // 남은 배달 가능량
    int pickup_allowance = 0;  // 남은 수거 가능량

    // 가장 먼 집부터 거꾸로 확인
    for (int i = n - 1; i >= 0; i--) {
        int cnt = 0; // 해당 집을 방문해야 하는 횟수

        // 현재 집에 처리할 물량이 남아있는지 확인 (이전 방문의 여유분으로 처리 가능한지)
        deliver_allowance -= deliveries[i];
        pickup_allowance -= pickups[i];

        // 여유분이 음수가 되면, 그만큼 더 방문해서 처리해야 함
        while (deliver_allowance < 0 || pickup_allowance < 0) {
            deliver_allowance += cap;
            pickup_allowance += cap;
            cnt++;
        }

        // 방문 횟수 * 거리 * 2(왕복)를 더함
        if (cnt > 0) {
            answer += (long long)(i + 1) * cnt * 2;
        }
    }

    return answer;
}