import java.util.*; 

class Solution {
    
    List<Long> answer = new ArrayList<>();
    HashMap<Long, Long> nextRoom = new HashMap<>(); 
    
    // 가능한 다음방 찾기
    public long find(long cur){
        if(!nextRoom.containsKey(cur)) return cur; 
        long val = find(nextRoom.get(cur));
        nextRoom.put(cur, val);
        return val;
    }
    
    public long[] solution(long k, long[] room_number) { 
        // k: 10^12 -> map 사용

        for(long r : room_number){ // 200,000
            // map에 없으면 원하는 방, map 다음껄로 갱신
            if(!nextRoom.containsKey(r)){
                answer.add(r); 
                nextRoom.put(r, r+1);
            }
            // map에 있으면 find로 다음방 찾고, 다음걸로 갱신
            else{
                long nxt = find(r); // 시간 단축해야함
                answer.add(nxt);
                nextRoom.put(nxt, nxt+1);
            }
        }
        
        // 각 고객에게 배정되는 방 번호를 순서대로 배열에 담아 return 
        return answer.stream().mapToLong(i->i).toArray();
    }
}