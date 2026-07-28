import java.util.*;

class Solution {

    public int solution(int[] people, int limit) {
        int answer = 0;
        
        Arrays.sort(people);
        
        // 가장 무거운 사람 태우고 공간 남으면 가능한 사람 중 무거운 사람
        int light = 0; int heavy = people.length-1;
        while(light <= heavy){
            int first = people[heavy]; 
            if(people[light] <= (limit - first)){
                light++;
            }; 
            heavy--;
                                
            answer++;
        }
        

        // 모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값
        return answer;
    }
}