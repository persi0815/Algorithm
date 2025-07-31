import java.util.*; 
/*
내구도 가진 건물이 각 칸마다 하나씩 있음. 적은 건물들을 공격해 파괴하려 함. 
건물은 공격을 받으면 내구도가 감소하고, 내구도가 0 이하가 되면 파괴됨. 
아군은 회복 스킬 사용하여 건물들의 내구도 높이려함. 
완탐: 100 * 100 * 100 + 100 * 100 = 1,010,000
*/
class Solution {
    public int solution(int[][] board, int[][] skill) {
        int n = board.length;
        int m = board[0].length;
        int[][] diff = new int[n + 2][m + 2]; // +2는 인덱스 초과 방지

        // 1. skill 마킹
        for (int[] s : skill) {
            int type = s[0], r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4], degree = s[5];
            int val = (type == 1) ? -degree : degree;

            diff[r1][c1] += val;
            diff[r1][c2 + 1] -= val;
            diff[r2 + 1][c1] -= val;
            diff[r2 + 1][c2 + 1] += val;
        }
        

        // 2. 가로 누적합
        for (int i = 0; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        // 3. 세로 누적합
        for (int j = 0; j < m + 1; j++) {
            for (int i = 1; i < n + 1; i++) {
                diff[i][j] += diff[i - 1][j];
            }
        }

        // 4. 최종 적용 및 파괴되지 않은 건물 개수 세기
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] + diff[i][j] > 0) answer++;
            }
        }

        return answer;
    }
}