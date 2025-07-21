import java.util.*; 
/*
완탐? dp?
-> dp로 dp[특정 값] = 사용횟수의 최솟값
사칙연산 하나씩?
어떻게 모든 경우를 다 생각할 수 있을까? 
*/

class Solution {
    
    // 숫자와 number가 주어질 때, n과 사칙연산만 이용해서 표현할 수 있는 방법
    public int solution(int N, int number) {
        if (N == number) return 1;

        // 1부터 8까지 사용한 결과를 저장할 리스트 (index = 사용 횟수)
        List<Set<Integer>> dp = new ArrayList<>();
        for (int i = 0; i <= 8; i++) dp.add(new HashSet<>());

        // N을 i번 반복한 수 추가 (e.g., 5, 55, 555, ...)
        for (int i = 1; i <= 8; i++) {
            int nn = Integer.parseInt(String.valueOf(N).repeat(i));
            dp.get(i).add(nn);

            // i를 j + (i-j)로 나누는 방식으로 만들 수 있는 조합 계산
            for (int j = 1; j < i; j++) {
                for (int op1 : dp.get(j)) {
                    for (int op2 : dp.get(i - j)) {
                        dp.get(i).add(op1 + op2);
                        dp.get(i).add(op1 - op2);
                        dp.get(i).add(op1 * op2);
                        if (op2 != 0) dp.get(i).add(op1 / op2);
                    }
                }
            }

            if (dp.get(i).contains(number)) return i;
        }

        return -1;
    }
}