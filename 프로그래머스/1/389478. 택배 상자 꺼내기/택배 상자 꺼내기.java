import java.util.*;

class Solution {
    public int solution(int n, int w, int num) {
        // 전체 층 수(0-indexed로 rows는 개수)
        int rows = (n + w - 1) / w;

        // num이 있는 층 r(0-index), 그 층에서의 인덱스 k(0..w-1)
        int r = (num - 1) / w;
        int k = (num - 1) % w;

        // num의 가로 좌표 x (층 방향에 따라 좌우 반전)
        int x = (r % 2 == 0) ? k : (w - 1 - k);

        // 마지막 층의 실제 칸 수
        int lastCount = n - (rows - 1) * w;
        if (lastCount == 0) lastCount = w;

        int ans = 0;
        // num의 층부터 맨 위 층까지, x열이 존재하는지 확인
        for (int t = r; t < rows; t++) {
            boolean leftToRight = (t % 2 == 0);
            int countInRow = (t == rows - 1) ? lastCount : w;

            // 해당 층에서 실제로 채워진 열 구간 [L, R]
            int L, R;
            if (leftToRight) {
                L = 0; R = countInRow - 1;
            } else {
                L = w - countInRow; R = w - 1;
            }

            if (x >= L && x <= R) ans++; // 그 층에 x열 상자가 있으면 꺼내야 함(자기 자신 포함)
        }

        return ans;
    }
}
