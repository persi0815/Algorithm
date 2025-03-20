#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, d, k, c;

int get_various(vector<int>& belt) {
    unordered_map<int, int> m;  // 초밥 번호 -> 개수
    int max_variety = 0, current_variety = 0;

    // 초기 윈도우 설정 (첫 k개의 초밥)
    for (int i = 0; i < k; i++) {
        if (m[belt[i]] == 0) current_variety++;  // 새로운 종류 추가 시 증가
        m[belt[i]]++;
    }

    // 쿠폰 초밥 추가 (항상 유지)
    if (m[c] == 0) current_variety++;
    m[c]++;

    max_variety = current_variety;  // 초기 최대값 설정

    // 슬라이딩 윈도우 시작
    int left = 0, right = k - 1;
    for (int i = 0; i < n; i++) {
        // 기존 초밥 제거 (왼쪽 이동)
        if (--m[belt[left]] == 0) current_variety--;  // 초밥 개수가 0이 되면 종류 감소
        left++;

        // 새로운 초밥 추가 (오른쪽 이동)
        right = (right + 1) % n;
        if (m[belt[right]] == 0) current_variety++;  // 새로운 종류 추가
        m[belt[right]]++;

        // 최대 초밥 종류 수 갱신
        max_variety = max(max_variety, current_variety);
    }

    return max_variety;
}

int main() {
    cin >> n >> d >> k >> c;
    vector<int> belt(n);
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }

    cout << get_various(belt) << endl;
    return 0;
}
