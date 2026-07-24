import java.util.*;

class Solution {
    Map<String, List<Integer>> scores = new HashMap<>();

    // 리스트에서 해당 점수 이상인 지원자 수 반환
    public int binarySearch(List<Integer> scores, int targetScore) {
        int left = 0;
        int right = scores.size() - 1;
        int point = scores.size();

        while (left <= right) {
            int mid = (left + right) / 2;

            if (scores.get(mid) >= targetScore) {
                point = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return scores.size() - point;
    }

    public int[] solution(String[] info, String[] query) {
        List<Integer> answer = new ArrayList<>();
        scores.clear();

        // 지원자 정보를 24가지 조건 중 하나의 Map에 저장
        for (String content : info) {
            String[] values = content.split(" ");

            String key = values[0] + "_"
                       + values[1] + "_"
                       + values[2] + "_"
                       + values[3] + "_";

            int score = Integer.parseInt(values[4]);

            scores.computeIfAbsent(key, ignored -> new ArrayList<>())
                  .add(score);
        }

        // 각 조건에 저장된 점수를 오름차순 정렬
        for (List<Integer> scoreList : scores.values()) {
            Collections.sort(scoreList);
        }

        // 각 쿼리에 맞는 조건을 찾고 이진 탐색으로 인원수 계산
        for (String content : query) {
            String[] values = content.split(" ");

            List<String> conditions = new ArrayList<>();

            // 쿼리 형식:
            // 언어 and 직군 and 경력 and 소울푸드 점수
            for (int i = 0; i <= 6; i += 2) {
                if (!values[i].equals("-")) {
                    conditions.add(values[i]);
                }
            }

            int targetScore = Integer.parseInt(values[7]);
            int count = 0;

            // 적합한 key 찾기
            for (Map.Entry<String, List<Integer>> entry : scores.entrySet()) {
                String key = entry.getKey();
                boolean fit = true;

                for (String condition : conditions) {
                    if (!key.contains(condition)) {
                        fit = false;
                        break;
                    }
                }

                if (fit) {
                    count += binarySearch(entry.getValue(), targetScore);
                }
            }

            answer.add(count);
        }

        // 각 쿼리에 해당하는 인원 수 반환
        return answer.stream()
                     .mapToInt(Integer::intValue)
                     .toArray();
    }
}