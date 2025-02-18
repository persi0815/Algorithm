#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void process_test_case() {
    int k;
    cin >> k;

    priority_queue<int> max_heap; // 최대 힙 (최댓값 삭제 용)
    priority_queue<int, vector<int>, greater<int>> min_heap; // 최소 힙 (최솟값 삭제 용)
    unordered_map<int, int> count; // 각 숫자의 실제 개수를 저장

    int valid_count = 0; // 실제 큐에 남아 있는 유효한 숫자의 개수

    for (int i = 0; i < k; i++) {
        char cmd;
        int n;
        cin >> cmd >> n;

        if (cmd == 'I') { // 삽입 연산
            max_heap.push(n);
            min_heap.push(n);
            count[n]++;
            valid_count++;
        }
        else if (cmd == 'D') { // 삭제 연산
            if (valid_count == 0) continue; // 큐가 비어있다면 삭제 무시

            if (n == 1) { // 최댓값 삭제
                while (!max_heap.empty()) {
                    int top = max_heap.top();
                    max_heap.pop();
                    if (count[top] > 0) { // 실제 존재하는 값이라면 삭제 수행
                        count[top]--;
                        valid_count--;
                        break;
                    }
                }
            }
            else if (n == -1) { // 최솟값 삭제
                while (!min_heap.empty()) {
                    int top = min_heap.top();
                    min_heap.pop();
                    if (count[top] > 0) { // 실제 존재하는 값이라면 삭제 수행
                        count[top]--;
                        valid_count--;
                        break;
                    }
                }
            }
        }
    }

    // 최종적으로 남아있는 값 중 최댓값과 최솟값 찾기
    if (valid_count == 0) {
        cout << "EMPTY" << endl;
    }
    else {
        int max_val, min_val;

        // 최댓값 찾기
        while (!max_heap.empty()) {
            max_val = max_heap.top();
            if (count[max_val] > 0) break; // 유효한 값이면 종료
            max_heap.pop();
        }

        // 최솟값 찾기
        while (!min_heap.empty()) {
            min_val = min_heap.top();
            if (count[min_val] > 0) break; // 유효한 값이면 종료
            min_heap.pop();
        }

        cout << max_val << " " << min_val << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        process_test_case();
    }

    return 0;
}
