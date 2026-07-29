import java.util.*; 

class Solution {
    
    public int[] solution(int n, long left, long right) {
        List<Integer> list = new ArrayList<>(); 
        
        // left ~ right까지 수 알아내기
        for(long id = left; id <= right ; id++){ // 10^5
            long row = id / n + 1; 
            long col = id % n + 1; 
            int num = (int)Math.max(row, col); 
            list.add(num); 
        }
        
        return list.stream().mapToInt(i->i).toArray();
    }
}