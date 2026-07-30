import java.util.*; 

class Solution {
    public int[] solution(String[] operations) { // 1,000,000 
        
        HashMap<Integer, Integer> nums = new HashMap<>(); 
        
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> {
            return Integer.compare(b, a);
        }); 
        PriorityQueue<Integer> minHeap = new PriorityQueue<>((a, b) -> {
            return Integer.compare(a, b);
        }); 
        
        for(String operation : operations){
            String[] order = operation.split(" ");
            if(order[0].equals("I")){ // 삽입
                int n = Integer.parseInt(order[1]); 
                // System.out.println("insert: " + n);
                nums.merge(n, 1, Integer::sum);
                minHeap.offer(n); maxHeap.offer(n);
                
            }else if(order[0].equals("D")){
                if(order[1].equals("1")){ // 최댓값 삭제              
                    deleteMax(maxHeap,nums);
                }else{ // 최솟값 삭제
                    deleteMin(minHeap, nums);

                }
            }
        }
        
        // 모든 연산을 처리한 후 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]을 return
        int min = 0; int max = 0;
        
        String m = deleteMax(maxHeap, nums); 
        if(!m.equals("-")) max = Integer.parseInt(m);
        minHeap.offer(max); nums.merge(max, 1, Integer::sum);
        
        m = deleteMin(minHeap, nums); 
        if(!m.equals("-")) min = Integer.parseInt(m);
        
        return new int[]{max, min};
    }
    
    public String deleteMax(PriorityQueue<Integer> maxHeap, HashMap<Integer, Integer> nums){
        int max = 0; boolean avail = false;
        while(maxHeap.size() != 0) { 
            // 이제 heap에 데이터가 없음
            if(maxHeap.size() == 0) break;
            // 데이터 뽑기
            max = maxHeap.poll();
            // 데이터가 이미 뽑혔음
            if(!nums.containsKey(max) || (nums.containsKey(max) && nums.get(max) <= 0)) continue;
            // 뽑혔으니 데이터 제거
            nums.merge(max, -1, Integer::sum);
            // System.out.println("del: " + max);
            avail = true;
            break;
        }
        if(avail) return String.valueOf(max);
        else return "-";
        
    }
    public String deleteMin(PriorityQueue<Integer> minHeap, HashMap<Integer, Integer> nums){
        int min = 0; boolean avail = false;
        while(minHeap.size() != 0) { 
            // 이제 heap에 데이터가 없음
            if(minHeap.size() == 0) break;
            // 데이터 뽑기
            min = minHeap.poll();
            // 데이터가 이미 뽑혔음
            if(!nums.containsKey(min) || (nums.containsKey(min) && nums.get(min) <= 0)) continue;
            // 뽑혔으니 데이터 제거
            nums.merge(min, -1, Integer::sum);
            // System.out.println("del: " + min);
            avail = true;
            break;
        }
        if(avail) return String.valueOf(min);
        else return "-";
    }
}