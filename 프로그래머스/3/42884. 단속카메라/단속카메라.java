import java.util.*;

class Solution {
    
    // 모든 차량이 한 번은 단속용 카메라를 만나도록 하려면 최소 몇 대의 카메라를 설치해야 하는지
    public int solution(int[][] routes) {
        
        
        Arrays.sort(routes, (a, b) -> {
            if(a[1]!=b[1]) return Integer.compare(a[1], b[1]); // 진출 시점 오름차순
            else return Integer.compare(a[0], b[0]); 
        });
        
        int spot = routes[0][1];
        int answer = 1;
        for(int[] r : routes){ // 10,000
            if(r[0] <= spot && r[1] >= spot) continue; 
            else{
                spot = r[1]; 
                answer++;
            }
        }
        
        
        return answer;
    }
}