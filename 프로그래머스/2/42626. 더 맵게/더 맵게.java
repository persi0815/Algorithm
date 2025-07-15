import java.util.*; 
/*
모든 음식의 스코빌 지수를 k이상으로 만들고자 함. 
스코빌 지수 낮은 두개의 음식 섞어서 새로운 음식 생성 -> 모든 음식의 스코빌 지수가 k 이상이 될 때까지. 

*/

class Solution {
    public int solution(int[] scoville, int K) {
        int num = scoville.length;
        int cnt = 0;
        
        // 값 넣기
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i = 0; i < num; i++){
            pq.offer(scoville[i]);
        }
        
        // 낮은거 두개 섞어서 새거 만들어 넣기
        // 가장 낮은게 k 이상이라면 그때 횟수 return 
        while(pq.size() >= 2 && pq.peek() < K){
            int a = pq.poll(); int b = pq.poll(); 
            pq.offer(a+(b*2));
            cnt++;
        }
        // 마지막 값이 k 보다 작으면
        return pq.peek() < K ? -1 : cnt;
    }
}