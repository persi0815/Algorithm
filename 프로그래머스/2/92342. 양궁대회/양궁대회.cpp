#include <vector>
#include <iostream>

using namespace std;

int maxDiff = 0;
vector<int> answer = {-1};

// 낮은 점수를 더 많이 맞힌 배열을 찾는 함수
bool isBetter(vector<int>& currentLion) {
    for (int i = 10; i >= 0; i--) {
        if (currentLion[i] > answer[i]) return true;
        if (currentLion[i] < answer[i]) return false;
    }
    return false; // 다 같으면
}

void dfs(int idx, int arrows, vector<int>& info, vector<int>& lion) {
    // 기저 조건: 모든 점수(10점~0점)에 대해 결정을 마쳤을 때
    if (idx == 11) {
        // 남은 화살이 있다면 모두 0점에 몰아주기 (꼭 n발을 다 쏴야 함)
        lion[10] += arrows;

        int rScore = 0; // 라이언 점수
        int aScore = 0; // 어피치 점수

        // 점수 계산
        for (int i = 0; i < 11; i++) {
            if (info[i] == 0 && lion[i] == 0) continue; // 둘 다 0발이면 점수 없음
            if (info[i] < lion[i]) rScore += (10 - i);
            else aScore += (10 - i);
        }

        int diff = rScore - aScore;
        if (diff > 0) { // 라이언이 이긴 경우
            if (diff > maxDiff) {
                maxDiff = diff;
                answer = lion;
            } else if (diff == maxDiff) {
                // 점수 차이가 같다면 낮은 점수를 더 많이 맞힌 경우 선택
                if (isBetter(lion)) answer = lion;
            }
        }

        lion[10] -= arrows; // 백트래킹을 위한 원복
        return;
    }

    // 완탐으로 라이언 점수 매기기 (가져가거나 안가져가거나)
    
    // 1. 라이언이 해당 점수를 가져가는 경우 (어피치보다 1발 더 쏘기)
    if (arrows > info[idx]) {
        lion[idx] = info[idx] + 1;
        dfs(idx + 1, arrows - (info[idx] + 1), info, lion);
        lion[idx] = 0; // 원복
    }

    // 2. 라이언이 해당 점수를 포기하는 경우 (0발 쏘기)
    dfs(idx + 1, arrows, info, lion);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> lion(11, 0);
    maxDiff = 0;
    answer = {-1};

    dfs(0, n, info, lion);

    return answer;
}