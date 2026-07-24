import java.util.*;

class Solution {
    int maxDiff = 0;
    int[] answer = {-1};

    // 낮은 점수를 더 많이 맞힌 배열인지 확인
    public boolean isBetter(int[] currentLion) {
        for (int i = 10; i >= 0; i--) {
            if (currentLion[i] > answer[i]) return true;
            if (currentLion[i] < answer[i]) return false;
        }

        return false; // 모두 같은 경우
    }

    public void dfs(
        int idx,
        int arrows,
        int[] info,
        int[] lion
    ) {
        // 모든 점수에 대해 결정을 마친 경우
        if (idx == 11) {
            // 남은 화살을 모두 0점에 사용
            lion[10] += arrows;

            int lionScore = 0;
            int apeachScore = 0;

            // 점수 계산
            for (int i = 0; i < 11; i++) {
                // 두 선수 모두 화살을 맞히지 않은 점수
                if (info[i] == 0 && lion[i] == 0) continue;

                if (lion[i] > info[i]) {
                    lionScore += 10 - i;
                } else {
                    apeachScore += 10 - i;
                }
            }

            int diff = lionScore - apeachScore;

            // 라이언이 이긴 경우만 확인
            if (diff > 0) {
                if (diff > maxDiff) {
                    maxDiff = diff;
                    answer = lion.clone();
                } else if (diff == maxDiff && isBetter(lion)) {
                    // 점수 차이가 같으면 낮은 점수를 더 많이 맞힌 경우 선택
                    answer = lion.clone();
                }
            }

            // 백트래킹을 위한 원복
            lion[10] -= arrows;
            return;
        }

        // 1. 해당 점수를 가져가는 경우
        if (arrows > info[idx]) {
            lion[idx] = info[idx] + 1;

            dfs(
                idx + 1,
                arrows - lion[idx],
                info,
                lion
            );

            lion[idx] = 0; // 원복
        }

        // 2. 해당 점수를 포기하는 경우
        dfs(idx + 1, arrows, info, lion);
    }

    public int[] solution(int n, int[] info) {
        int[] lion = new int[11];

        maxDiff = 0;
        answer = new int[]{-1};

        dfs(0, n, info, lion);

        return answer;
    }
}