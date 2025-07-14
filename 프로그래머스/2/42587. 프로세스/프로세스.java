import java.util.*;
/*
규칙에 따라 관리될 때 프로세스가 몇 번째로 실행되나? 
1. 실행 대기 큐(Queue)에서 대기중인 프로세스 하나를 꺼냅니다.
2. 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스를 다시 큐에 넣습니다.
3. 만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행합니다.
  3.1 한 번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료됩니다.
  
큐! 이동할때마다 현재 위치를 갱신해주어야 함
대기중인 프로세스 중에 자신보다 큰 것 있는지 파악하려면 map 사용? {우선순위, 개수}
*/

// 우선순위, 프로세스 위치
class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0; // 해당 프로세스가 몇 번째로 실행되나?
        
        int num = priorities.length;
        Queue<Integer> queue = new LinkedList<>();
        Map<Integer, Integer> priorityNum = new HashMap<>();
        
        // 원소들 개수 입력
        for(int i = 0; i < num; i++){
            priorityNum.put(priorities[i], priorityNum.getOrDefault(priorities[i], 0) + 1);
        }
        
        // 큐에 넣기
        for(int i = 0; i < num; i++){
            queue.add(priorities[i]);
        }
        
        // 큐 이동 시키며 대기중인 프로세스 중에 자신보다 큰 것 없을 때 내보내기
        while(!queue.isEmpty()){
            int peek = queue.peek(); 
            
            // 맨앞 원소 뺄 수 있나 확인
            boolean can = true; 
            for(Integer key : priorityNum.keySet()){
                if(peek < key) {
                    can = false; break;
                }
            }
            
            
            if(can){
                if(location == 0) break;
                else answer ++;
                priorityNum.put(peek, priorityNum.get(peek) - 1);
                if(priorityNum.get(peek) <= 0) priorityNum.remove(peek);
            }else{
                queue.add(peek);
            }
            queue.poll(); 
            location = (location - 1 + queue.size()) % queue.size();
        }
        
        return answer + 1;
    }
}