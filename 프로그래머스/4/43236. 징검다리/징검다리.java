import java.util.*; 
/*
바위 몇개 없앴을 때 생기는 거리들의 최솟값인데, 그중 최댓값 탐색
완탐 -> n개 조합으로 골라서 제거하고 거리 전부 재서 최솟값들 모아서 그중 최댓값 구하기 -> 조합 구할때 시간복잡도 넘김
이진 -> 시작해서 거리 만들고 제거해가며 해당 길이 이상으로 만드는게 가능한지 판별 -> 가능! 9*log2(10) = 36 * 50000
*/

class Solution {
    
    // 끝 위치, 바위 위치, 제거 가능 개수
    public int solution(int end, int[] rocks, int n) {
        int answer = 0; 
        Arrays.sort(rocks);
        
        // int[] newRocks = new int[rocks.length + 1];
        // System.arraycopy(rocks, 0, newRocks, 0, rocks.length);
        // 무엇을 어디부터? 어디에 어디부터? 무엇을 얼마만큼
        // newRocks[rocks.length] = newValue;
        List<Integer> rocksList = new ArrayList<>();
        for(int rock: rocks) rocksList.add(rock);
        rocksList.add(end);

        
        int left = 1;
        int right = 1000000001;
        while(left <= right){
            int mid = (left + right)/2; // 거리의 최솟값. 이거 같거나 넘기면 바로 끊기.
            int avail = n;
            int len = 0;
            boolean can = true;
            int bef = 0;
            for(int rock : rocksList){
                len = (rock - bef);
                if(len < mid) { // 아직 길이가 부족해
                    avail--; // 제거권 사용하기
                }else{
                    bef = rock;
                }
                if(avail < 0) { // 제거권이 이제 없어. 
                    can = false;
                    break;
                }
                
            }
            if(can){
                left = mid + 1;
                answer = Math.max(mid, answer);
            }else{
                right = mid -1;
            }
            
        }
        
        
        
        
        return answer;
    }
}