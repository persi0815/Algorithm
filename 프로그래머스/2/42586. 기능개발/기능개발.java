import java.util.*;

/*
뒤의 기능들은 앞의 기능이 배포될 때 함께 배포됨
배포되어야 하는 순서대로 작업의 진도(100이 되어야), 개발 속도

각자 몇일 동안 작업을 해야 하는지 파악해야 함

*/

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int workNum = progresses.length;
        int[] answer = {}; // 각 배포마다 몇 개의 기능이 배포되나?
        
        // 각 작업이 끝날때까지 소요되는 시간 구하기
        List<Integer> workDay = new ArrayList<>();
        for(int i = 0; i < workNum; i++){
            Integer day = (100-progresses[i])%speeds[i] == 0 ?
                (100-progresses[i])/speeds[i] : (100-progresses[i])/speeds[i] + 1;
            
            workDay.add(day);
        }
        
        // 앞이 큰 것 기준으로 그보다 작은 것 한번에 묶어 세어 배열 넣기
        List<Integer> release = new ArrayList<>();
        int first = workDay.get(0); int num = 0;
        for(int i = 0; i < workNum; i++){
            if(first >= workDay.get(i)) {
                num++;
            }else{
                release.add(num); num = 1;
                first = workDay.get(i);
            }
        }
        if(num > 0) release.add(num);
        
        return answer = release.stream().mapToInt(i -> i).toArray();
    }
}