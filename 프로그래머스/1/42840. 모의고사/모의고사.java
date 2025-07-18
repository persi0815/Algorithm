import java.util.*; 
/*
정답 배열이 주어졌을때, 가장 많은 문제를 맞힌 사람은? 
가장 높은 점수 받은 사람이 여럿일 경우, return 하는 값을 오름차순으로!!!
*/

class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        
        int[] a = {1, 2, 3, 4, 5}; int a_idx = 0; int aa = 0;
        int[] b = {2, 1, 2, 3, 2, 4, 2, 5}; int b_idx = 0; int bb = 0;
        int[] c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; int c_idx = 0; int cc = 0;
        // 하나하나 보기
        for(int i = 0; i < answers.length; i++){
            int ans = answers[i];
            if (answers[i] == a[i % a.length]) aa++;
            if (answers[i] == b[i % b.length]) bb++;
            if (answers[i] == c[i % c.length]) cc++;
        }
        
        List<List<Integer>> res = new ArrayList<>(); 
        res.add(Arrays.asList(aa, 1));
        res.add(Arrays.asList(bb, 2));
        res.add(Arrays.asList(cc, 3));
        // 내림차순 정렬
        Collections.sort(res, (s, k) -> Integer.compare(k.get(0), s.get(0)));
        
        List<Integer> ans = new ArrayList<>(); 
        
        int max = res.get(0).get(0);
        for(int i = 0; i < 3; i++){
            if(res.get(i).get(0) == max) ans.add(res.get(i).get(1));
            else break;
        }
        
        return answer = ans.stream().mapToInt(i -> i).toArray();
    }
}