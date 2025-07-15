import java.util.*; 
/*
모든 연산을 처리한 후 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]을 return
빈 큐에서 데이터 삭제하라는 연산이 주어질 경우, 해당 연산 무시

값 넣을때 두개의 힙에 모두 데이터 넣고 map 갱신, 뺄때 map 보고 가능한지 판단 후 heap에서 제거
*/

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        int num = operations.length; 
        
        // {원소, 개수}
        Map<Integer, Integer> map = new HashMap<>();
        
        // 최솟값 삭제하기 위해
        PriorityQueue<Integer> min_heap = new PriorityQueue<>();
        // 최댓값 삭제하기 위해
        PriorityQueue<Integer> max_heap = new PriorityQueue<>(Collections.reverseOrder());
        
        // 명령어 수행
        for(int i = 0; i < num; i++){
            // System.out.println(i);
            String[] words = operations[i].split(" ");
            String order = words[0];
            Integer number = Integer.parseInt(words[1]);
            if("I".equals(order)){ // 삽입
                map.merge(number, 1, Integer::sum);
                min_heap.offer(number);
                max_heap.offer(number);
                
                // System.out.println(map);
                // System.out.println(max_heap);
                // System.out.println(min_heap);
            }else if("D".equals(order)){ // 제거
                if(map.isEmpty()) continue;
                if(number.equals(1)){ // 최댓값 삭제
                    while(true){
                        int key = max_heap.poll();
                        if(map.containsKey(key)){
                            // 하나 줄이기
                            map.merge(key, -1, Integer::sum);
                            // value가 0 되었다면 삭제
                            if(map.get(key) == 0) map.remove(key);
                            // 성공했다면 나가기
                            break;
                        }
                    }
                }else if(number.equals(-1)){ // 최솟값 삭제
                    while(true){
                        int key = min_heap.poll();
                        if(map.containsKey(key)){
                            // 하나 줄이기
                            map.merge(key, -1, Integer::sum);
                            // value가 0 되었다면 삭제
                            if(map.get(key) == 0) map.remove(key);
                            // 성공했다면 나가기
                            break;
                        }
                    }
                }
                // System.out.println(map);
                // System.out.println(max_heap);
                // System.out.println(min_heap);        
            }
        } // 명령어 수행 끝
        
        // map의 key 추출해서 정렬
        List<Integer> keys = new ArrayList<>(map.keySet());
        Collections.sort(keys); // 오름차순 정렬
        
        if(keys.isEmpty()){
            answer[0] = 0;
            answer[1] = 0;
        }else{
            answer[1] = keys.get(0);
            answer[0] = keys.get(keys.size()-1);
        }
        
        return answer; // 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]
    }
}