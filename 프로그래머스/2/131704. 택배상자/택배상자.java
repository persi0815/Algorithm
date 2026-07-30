import java.util.*;

class Solution {
    
    // 택배 기사님이 미리 알려준 순서에 맞게 영재가 택배상자를 실어야
    // 보조 컨테이너 벨트는 stack
    // 보조 컨테이너 벨트를 이용해도 기사님이 원하는 순서대로 상자를 싣지 못 한다면, 더 이상 상자를 싣지 않습니다.
    public int solution(int[] order) {
        
        int orderId = 0; // 현재 진행중인 택배 id
        
        Stack<Integer> stack = new Stack<>(); 
        int[] boxes = new int[order.length]; 
        for(int i = 0; i < order.length; i++) boxes[i] = i+1; 
        
        // list 에서 다음꺼 가져오거나 아님 stack의 peek()에서 가져오거나
        int boxId = 0; 
        for(orderId = 0; orderId < order.length; orderId++){
            int want = order[orderId]; // 원하는 박스
            boolean avail = false; 
            
            // 원하는 박스가 stack에 있어 -> stack pop하고 다음 order로
            if(!stack.isEmpty() && stack.peek() == want){
                stack.pop(); 
                avail = true;
                // System.out.println("1 " + want);
            }
            // 원하는 박스가 나올때까지 boxes에서 찾기 -> 찾으면 boxesId++하고 다음 order로
            while(!avail && boxId < order.length){
                int box = boxes[boxId];
                if(want == box){ 
                    avail = true;
                    boxId++; // 다음 박스로
                    // System.out.println("2 " + want);
                }
                else {
                    stack.push(box);  // 현재 박스 stack에 넣기
                    boxId++; // 다음 박스로
                    // System.out.println("3 " + want);
                }
            }
           
            // 원하는 박스가 boxes, stack 둘다에 없어 -> 불가능
            if(!avail){
                return orderId; // 영재가 몇 개의 상자를 실을 수 있는지 return
            }
            
        }

        // 전부 실을 수 있음
        return orderId;
    }
}