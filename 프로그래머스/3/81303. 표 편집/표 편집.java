import java.util.*;

class Node{
    int prev; int next; 
    public Node(int prev, int next){
        this.prev = prev; this.next = next;
    }
}
class Solution {
    boolean[] avail;
    Stack<Integer> stack = new Stack<>(); 
    List<Node> list = new ArrayList<>(); 
    
    public int goDown(int cur, int x){
        while(x > 0){
            cur = list.get(cur).next;
            x--;
        }
        return cur;
        // while(x > 0){
        //     cur++;
        //     if(avail[cur]){
        //         x--;
        //     }
        // }
        // return cur;
    }
    
    public int goUp(int cur, int x){
        while(x > 0){
            cur = list.get(cur).prev; 
            x--;
        }
        return cur;
        // while(x > 0){
        //     cur--;
        //     if(avail[cur]){
        //          x--;
        //     }
        // }
        // return cur;
    }
    
    public String solution(int n, int k, String[] cmd) {
        String answer = "";
        
        avail = new boolean[n];
        Arrays.fill(avail, true); 
        
        int cur = k; 

        // 연결 리스트 만들기
        list.add(new Node(-1, 1));
        for(int i = 1; i < n-1; i++){
            list.add(new Node(i-1, i+1));
        }
        list.add(new Node(n-2, -1));
        
        // 명령 처리
        for(String s : cmd){ 
            // 200,000(cmd) * 1,000,000(원소) -> 시간 초과 
            // => 바로 앞이나 뒤에 있는 원소가 뭔지 알아야 함. 
            // 200,000(cmd) * 300,000(x) -> cmd에 등장하는 모든 X들의 값을 합친 결과가 1,000,000 이하인 경우만 입력으로 주어진다는 조건으로 해결
            // => 200,000(cmd) + 1,000,000 (문제 없음!!)
            char order = s.charAt(0);
            if(order == 'U'){ // 현재 선택된 행에서 X칸 위에 있는 행을 선택
                int x = Integer.parseInt(s.substring(2));
                cur = goUp(cur, x);
                
            }else if(order == 'D'){ // 현재 선택된 행에서 X칸 아래에 있는 행을 선택
                int x = Integer.parseInt(s.substring(2));
                cur = goDown(cur, x);
                
            }else if(order == 'C'){ // 현재 선택된 행을 삭제한 후, 
                avail[cur] = false;
                stack.push(cur); 
                // list 갱신
                int prev = list.get(cur).prev;
                int next = list.get(cur).next;
                if (prev != -1) list.get(prev).next = next;
                if (next != -1) list.get(next).prev = prev;
                // 행 선택
                cur = (next != -1) ? next : prev; // 삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택 아니면 바로 아래 행을 선택
                
            }else if(order == 'Z'){ // 가장 최근에 삭제된 행을 원래대로 복구. 현재 선택된 행은 바뀌지 않음
                int restored = stack.pop();
                avail[restored] = true;
                // list 복구
                int prev = list.get(restored).prev;
                int next = list.get(restored).next;
                if (prev != -1) list.get(prev).next = restored;
                if (next != -1) list.get(next).prev = restored;
            }
        }
        
        // 표의 0행부터 n - 1행까지에 해당되는 O, X를 순서대로 이어붙인 문자열 형태로 return
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++){
            if(avail[i]) sb.append("O"); 
            else sb.append("X");
        }
        
        return sb.toString();
    }
}