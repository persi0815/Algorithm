import java.util.*;

class Solution {

    /*
    주사위 고름 -> 승패, 무승부 모두 기록 -> 승이 가장 많은 거 골라 진행
    1. 조합으로 주사위 골라
    2. 완탐으로 각 상황에 이길지 질지 무승부인지 기록
    3. 승이 가장 많은거 골라 답 입력
    */

    // n개의 주사위 중 n/2개를 선택하는 모든 조합 생성
    public List<List<Integer>> combinations(int n) {
        List<List<Integer>> result = new ArrayList<>();
        makeCombination(1, n, n / 2, new ArrayList<>(), result);
        return result;
    }

    public void makeCombination(
        int start,
        int n,
        int targetSize,
        List<Integer> current,
        List<List<Integer>> result
    ) {
        if (current.size() == targetSize) {
            result.add(new ArrayList<>(current));
            return;
        }

        for (int diceNumber = start; diceNumber <= n; diceNumber++) {
            current.add(diceNumber);
            makeCombination(diceNumber + 1, n, targetSize, current, result);
            current.remove(current.size() - 1);
        }
    }

    // 선택한 주사위에서 나올 수 있는 합과 각 합의 등장 횟수 계산
    public void findSums(
        List<Integer> diceNumbers,
        int[][] dice,
        int depth,
        int sum,
        Map<Integer, Integer> sums
    ) {
        if (depth == diceNumbers.size()) {
            sums.put(sum, sums.getOrDefault(sum, 0) + 1);
            return;
        }

        int diceIndex = diceNumbers.get(depth) - 1;

        for (int face = 0; face < 6; face++) {
            findSums(
                diceNumbers,
                dice,
                depth + 1,
                sum + dice[diceIndex][face],
                sums
            );
        }
    }

    // A가 선택한 주사위 조합의 승리 횟수 계산
    public long winCount(List<Integer> a, int[][] dice) {
        List<Integer> b = new ArrayList<>();
        boolean[] selected = new boolean[dice.length + 1];

        for (int diceNumber : a) {
            selected[diceNumber] = true;
        }

        for (int diceNumber = 1; diceNumber <= dice.length; diceNumber++) {
            if (!selected[diceNumber]) {
                b.add(diceNumber);
            }
        }

        // A와 B가 만들 수 있는 합과 각 합의 등장 횟수
        Map<Integer, Integer> aSums = new HashMap<>();
        Map<Integer, Integer> bSums = new HashMap<>();

        findSums(a, dice, 0, 0, aSums);
        findSums(b, dice, 0, 0, bSums);

        long wins = 0;

        for (Map.Entry<Integer, Integer> aEntry : aSums.entrySet()) {
            for (Map.Entry<Integer, Integer> bEntry : bSums.entrySet()) {
                if (aEntry.getKey() > bEntry.getKey()) {
                    wins += (long) aEntry.getValue() * bEntry.getValue();
                }
            }
        }

        return wins;
    }

    public int[] solution(int[][] dice) {
        List<Integer> bestCombination = new ArrayList<>();
        long maxWins = -1;

        // 조합으로 A가 가져갈 주사위 선택
        List<List<Integer>> combinationList = combinations(dice.length);

        // 각 조합의 승리 횟수를 계산해 최댓값 갱신
        for (List<Integer> combination : combinationList) {
            long wins = winCount(combination, dice);

            if (wins > maxWins) {
                maxWins = wins;
                bestCombination = new ArrayList<>(combination);
            }
        }

        // A가 가져갈 주사위 번호를 오름차순으로 반환
        return bestCombination.stream()
            .mapToInt(Integer::intValue)
            .toArray();
    }
}