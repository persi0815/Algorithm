import java.util.*; 


class Solution {
    
    int[][] area; 
    
    // 시계방향 회전, 회전한 것 중 가장 작은 수 반환
    public int spin(int y1, int x1, int y2, int x2){
        int min_num = area[y1][x1]; 
        
        int cur = area[y1][x1]; int nxt = -1; 
        for(int i = x1+1; i <= x2; i++){
            nxt = area[y1][i]; area[y1][i] = cur; 
            cur = nxt;
            min_num = Math.min(min_num, nxt);
        }
        for(int i = y1+1; i <= y2; i++){
            nxt = area[i][x2]; area[i][x2] = cur; 
            cur = nxt;
            min_num = Math.min(min_num, nxt);
        }
        for(int i = x2-1; i >= x1; i--){
            nxt = area[y2][i]; area[y2][i] = cur; 
            cur = nxt;
            min_num = Math.min(min_num, nxt);
        }
        for(int i = y2-1; i >= y1; i--){
            nxt = area[i][x1]; area[i][x1] = cur; 
            cur = nxt;
            min_num = Math.min(min_num, nxt);
        }
        
        return min_num;
    }
    
    public int[] solution(int rows, int columns, int[][] queries) {
        area = new int[rows+1][columns+1]; 
        // 배열 채우기
        int num = 1; 
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= columns; j++){
                area[i][j] = num++;
            }
        }
        
        // 정답 배열
        List<Integer> ans = new ArrayList<>(); 
        // 회전시키면서 가장 작은거 찾기 -> ans 배열 삽입
        for(int[] q : queries){
            int y1 = q[0]; int x1 = q[1]; int y2 = q[2]; int x2= q[3];
            
            // 회전시키기
            ans.add(spin(y1, x1, y2, x2));
        }
        
        // 그 회전에 의해 위치가 바뀐 숫자들 중 가장 작은 숫자들을 순서대로 배열에 담아 return 
        return ans.stream().mapToInt(i -> i).toArray();
    }
}   