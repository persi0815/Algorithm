#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    int n, k; 
    cin >> n >> k; // 콘센트 개수, 사용 횟수

    vector<int> use(k); // 사용 순서 저장
    unordered_map<int, vector<int>> pos; // 전기기기별 사용 시점 저장
    set<int> hole; // 현재 콘센트에 꽂힌 기기 저장
    int result = 0;

    for (int i = 0; i < k; i++) {
        cin >> use[i];
        pos[use[i]].push_back(i); // 각 기기가 언제 사용되는지 저장
    }

    for (int i = 0; i < k; i++) {
        int now = use[i];
        pos[now].erase(pos[now].begin()); // 현재 사용한 시점 제거
        
        // 이미 꽂혀있다면 그냥 넘어감
        if (hole.find(now) != hole.end()) continue;

        // 콘센트에 자리가 남아있다면 꽂기
        if (hole.size() < n) {
            hole.insert(now);
        } else {
            // 앞으로 사용될 기기 중 가장 나중에 등장하는 것 제거
            int lastUse = -1, removeDevice = -1;
            for (int h : hole) {
                if (pos[h].empty()) { // 앞으로 안 쓰이는 기기가 있다면 바로 제거
                    removeDevice = h;
                    break;
                }
                // 가장 나중에 등장하는 기기 찾기
                if (pos[h].front() > lastUse) {
                    lastUse = pos[h].front();
                    removeDevice = h;
                }
            }

            // 콘센트에서 제거 후 새 기기 꽂기
            hole.erase(removeDevice);
            hole.insert(now);
            result++;
        }
    }

    cout << result;
}
