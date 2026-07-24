import java.util.*;

class Solution {

    public long solution(String expression) { // 연산 수식이 담긴 문자열
        long answer = 0;

        // expression에서 숫자와 연산자 분리
        List<String> expressions = new ArrayList<>();
        StringBuilder number = new StringBuilder();

        for (char c : expression.toCharArray()) {
            if (Character.isDigit(c)) {
                number.append(c);
            } else {
                expressions.add(number.toString());
                number.setLength(0);
                expressions.add(String.valueOf(c));
            }
        }

        expressions.add(number.toString()); // 마지막 숫자

        // 연산자 우선순위의 모든 경우
        String[][] priorities = {
            {"+", "-", "*"},
            {"+", "*", "-"},
            {"-", "+", "*"},
            {"-", "*", "+"},
            {"*", "+", "-"},
            {"*", "-", "+"}
        };

        // 각 연산자 우선순위에 따라 계산
        for (String[] priority : priorities) {
            List<String> tempExpressions = new ArrayList<>(expressions);

            // 현재 우선순위의 연산자부터 계산
            for (String currentOperator : priority) {
                List<String> progress = new ArrayList<>();

                progress.add(tempExpressions.get(0));

                // 연산자와 그 뒤의 숫자를 묶어서 처리
                for (int i = 1; i < tempExpressions.size(); i += 2) {
                    String operator = tempExpressions.get(i);
                    String secondNumber = tempExpressions.get(i + 1);

                    // 현재 계산할 연산자가 아니라면 그대로 저장
                    if (!operator.equals(currentOperator)) {
                        progress.add(operator);
                        progress.add(secondNumber);
                        continue;
                    }

                    // 현재 연산자라면 직전 숫자와 다음 숫자를 계산
                    long first = Long.parseLong(progress.remove(progress.size() - 1));
                    long second = Long.parseLong(secondNumber);
                    long result;

                    if (currentOperator.equals("+")) {
                        result = first + second;
                    } else if (currentOperator.equals("-")) {
                        result = first - second;
                    } else {
                        result = first * second;
                    }

                    progress.add(String.valueOf(result));
                }

                tempExpressions = progress;
            }

            // 해당 우선순위로 계산한 결과의 절댓값 갱신
            long result = Math.abs(Long.parseLong(tempExpressions.get(0)));
            answer = Math.max(answer, result);
        }

        return answer;
    }
}