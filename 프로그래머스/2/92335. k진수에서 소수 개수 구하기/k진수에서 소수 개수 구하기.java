class Solution {

    private boolean isPrime(long number) {
        if (number < 2) return false;

        for (long i = 2; i * i <= number; i++) {
            if (number % i == 0) return false;
        }
        return true;
    }

    public int solution(int n, int k) {
        int answer = 0;

        // Integer.toString(int i, int radix)는 정수 i를 radix진법 문자열로 변환
        String converted = Integer.toString(n, k);
        // System.out.println(converted);

        for (String value : converted.split("0+")) {
            if (!value.isEmpty() && isPrime(Long.parseLong(value))) {
                answer++;
            }
        }

        return answer;
    }
}