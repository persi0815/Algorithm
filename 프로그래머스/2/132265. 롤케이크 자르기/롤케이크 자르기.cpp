#include <vector>
#include <unordered_set>

using namespace std;

// 특정 지점 mid에서 잘랐을 때 양쪽의 종류 수를 반환
pair<int, int> get_counts(const vector<int>& topping, int mid) {
    unordered_set<int> left_s;
    unordered_set<int> right_s;
    
    for (int i = 0; i < mid; ++i) left_s.insert(topping[i]);
    for (int i = mid; i < topping.size(); ++i) right_s.insert(topping[i]);
    
    return {left_s.size(), right_s.size()};
}

int solution(vector<int> topping) {
    int n = topping.size();
    int start_point = -1, end_point = -1;

    // 1. Lower Bound 찾기 (시작점)
    int low = 1, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        auto counts = get_counts(topping, mid);
        if (counts.first >= counts.second) {
            if (counts.first == counts.second) start_point = mid;
            high = mid - 1;
        } else low = mid + 1;
    }

    if (start_point == -1) return 0;

    // 2. Upper Bound 찾기 (끝점)
    low = 1, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        auto counts = get_counts(topping, mid);
        if (counts.first <= counts.second) {
            if (counts.first == counts.second) end_point = mid;
            low = mid + 1;
        } else high = mid - 1;
    }

    return (end_point == -1) ? 0 : end_point - start_point + 1;
}