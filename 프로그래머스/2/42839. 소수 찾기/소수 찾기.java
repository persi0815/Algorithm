import java.util.*; 
/*
한자리 숫자가 적힌 종이 조각이 흩어져있다. 
흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 한다. 

한 자리수로 나누기
맨 앞에 0이면 안됨. 개수 정하고 순열로 만들기
일단 만들고 소수인지 아닌지 판별

*/

class Solution {
    // 순열을 이용해 해당 길이로 만들 수 있는 모든 숫자들 반환
    Set<Integer> permutations = new HashSet<>(); // 중복 제거를 위해 Set 사용

     public void permutation(String permu, List<String> nums, boolean[] visited, int len) {
        if (permu.length() == len) {
            permutations.add(Integer.parseInt(permu));
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 0으로 시작하는 수 제외
            if (permu.equals("") && nums.get(i).equals("0")) continue;

            if (!visited[i]) {
                visited[i] = true;
                permutation(permu + nums.get(i), nums, visited, len);
                visited[i] = false;
            }
        }
    }

    // 소수 판별
    public boolean isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;

        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) return false;
        }

        return true;
    }
    
    // 각 종이에 적힌 숫자가 적힌 문자열
    public int solution(String numbers) {
        List<String> nums = new ArrayList<>(); 
        for(int i = 0; i < numbers.length(); i++){
            nums.add(String.valueOf(numbers.charAt(i)));
        }
        // 오름차순 정렬
        Collections.sort(nums);
        
        // 순열 만들기
        
        for(int len = 1; len <= numbers.length(); len++){
            boolean[] visited = new boolean[numbers.length()];
            permutation("", nums, visited, len);
        }
        
        // 소수 개수 세기
        int answer = 0;
        for (int num : permutations) {
            if (isPrime(num)) answer++;
        }
        
        return answer;
    }
}