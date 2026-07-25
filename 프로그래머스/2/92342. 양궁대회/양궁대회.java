import java.util.*;

class Solution {
    int maxDiff = 0;
    int[] answer = {-1};

    // 낮은 점수를 더 많이 맞힌 배열인지 확인
    public boolean isBetter(int[] currentLion) {
        for (int i = 10; i >= 0; i--) { // 인덱스와 점수 반대로 매핑
            if (currentLion[i] > answer[i]) return true;
            if (currentLion[i] < answer[i]) return false;
        }
        return false; // 모두 같은 경우
    }

    public void dfs(int idx, int arrows, int[] info, int[] lion) {
        // 모든 점수에 대해 결정을 마친 경우
        if (idx == 11) {
            // 남은 화살을 모두 0점에 사용!!
            lion[10] += arrows;

            int lionScore = 0;
            int apeachScore = 0;

            // 점수 계산
            for (int i = 0; i < 11; i++) {
                // 두 선수 모두 화살을 맞히지 않은 점수
                if (info[i] == 0 && lion[i] == 0) continue;
                // 둘이 차이가 나는 경우 각각에게 점수 배정
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
                    answer = lion.clone(); // 배열 깊은 복사!!
                } else if (diff == maxDiff && isBetter(lion)) {
                    // 점수 차이가 같으면 낮은 점수를 더 많이 맞힌 경우 선택
                    answer = lion.clone();
                }
            }

            // 백트래킹을 위한 원복!! - 원복은 파라미터 내용들! 해당 상황을 반영해야 하기에
            lion[10] -= arrows;
            return;
        }

        // 1. 해당 점수를 가져가는 경우
        if (arrows > info[idx]) {
            lion[idx] = info[idx] + 1;
            dfs(idx + 1, arrows - lion[idx], info, lion);
            lion[idx] = 0; // 원복!!
        }

        // 2. 해당 점수를 포기하는 경우
        dfs(idx + 1, arrows, info, lion);
    }

    public int[] solution(int n, int[] info) { // 어피치 점수
        int[] lion = new int[11];

        maxDiff = 0;
        answer = new int[]{-1}; // 라이언이 우승할 수 없는 경우(무조건 지거나 비기는 경우)

        dfs(0, n, info, lion);

        // 라이언이 가장 큰 점수 차이로 우승하기 위해 n발의 화살을 어떤 과녁 점수에 맞혀야 하는지
        // 10점부터 0점까지 순서대로 정수 배열에 담아 return
        return answer;
    }
}