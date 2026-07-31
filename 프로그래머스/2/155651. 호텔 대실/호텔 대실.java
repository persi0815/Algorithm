import java.util.*; 

// 최소한의 객실만을 사용하여 예약 손님들을 받으려고
// 한 번 사용한 객실은 퇴실 시간을 기준으로 10분간 청소를 하고 다음 손님들이 사용
class Solution {
    
    class Room{
        int endTime; int roomNum; 
        public Room(int endTime, int roomNum){
            this.endTime = endTime; this.roomNum = roomNum; 
        }
    }
    
    public int toMinute(String time){
        int hour = Integer.parseInt(time.substring(0, 2));
        int min = Integer.parseInt(time.substring(3, 5));
        return hour*60 + min; 
    }
    
    public int solution(String[][] book_time) {
        // 코니에게 필요한 최소 객실의 수를 return
        int num = 0;
        
        Queue<Integer> avail = new ArrayDeque<>(); 
        PriorityQueue<Room> using = new PriorityQueue<>((a, b) -> {
            return Integer.compare(a.endTime, b.endTime); // 끝나는 시각으로 minHeap
        }); 
        
        // 부킹 시간으로 오름차순
        Arrays.sort(book_time, (a, b) -> {
            return Integer.compare(toMinute(a[0]), toMinute(b[0]));
        });
        
        // 하나씩 방 배정
        for(String[] book: book_time){
            int enter = toMinute(book[0]); 
            int exit = toMinute(book[1]) + 10;
            
            // 가능해진 방 using -> avail
            while(!using.isEmpty() && using.peek().endTime <= enter){
                avail.offer(using.peek().roomNum);
                using.poll(); 
            }
            
            // 가능한 방 있으면 거기에 배정
            if(!avail.isEmpty()){
                int room = avail.poll(); 
                using.offer(new Room(exit, room));
            }
            // 가능한 방 없으면 새로 만들어 배정
            else{
                using.offer(new Room(exit, ++num));
            }
            
        }
        
        return num;
    }
}