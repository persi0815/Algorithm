import java.util.*; 
/*
i부터 j번째 숫자까지 자르고 정렬했을때, k번째에 있는 수 구하기
기존 배열을 잘라서 새로운 배열 만들고 정렬
*/

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = {};
        int len = commands.length;
        System.out.println(len);
        List<Integer> ans = new ArrayList<>(); 
        for(int s = 0; s < commands.length; s++){
            
            int i = commands[s][0]; 
            int j = commands[s][1]; 
            int k = commands[s][2]; 
            
            int[] subArray = Arrays.copyOfRange(array, i-1, j);
            Arrays.sort(subArray);
            ans.add(subArray[k-1]);
        }
        
        return answer = ans.stream().mapToInt(i -> i).toArray();
    }
}