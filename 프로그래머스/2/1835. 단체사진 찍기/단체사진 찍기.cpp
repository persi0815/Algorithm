#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// 조건을 확인하는 함수를 분리하되, data를 인자로 받습니다.
bool check(const vector<string>& data, const vector<int>& loca) {
    for (const string& s : data) {
        int friend1 = s[0];
        int friend2 = s[2];
        char op = s[3];
        int dist_condition = s[4] - '0';
        
        // 실제 두 친구 사이의 간격 (사이의 사람 수이므로 -1)
        int actual_dist = abs(loca[friend1] - loca[friend2]) - 1;

        if (op == '=') {
            if (actual_dist != dist_condition) return false;
        } else if (op == '<') {
            if (actual_dist >= dist_condition) return false;
        } else if (op == '>') {
            if (actual_dist <= dist_condition) return false;
        }
    }
    return true;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    sort(friends.begin(), friends.end());

    // ASCII 값을 인덱스로 쓰기 위해 충분한 크기 확보
    vector<int> loca(100); 

    do {
        // 현재 순열에서의 각 친구 위치 저장
        for (int i = 0; i < 8; i++) {
            loca[friends[i]] = i;
        }

        if (check(data, loca)) {
            answer++;
        }
    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}