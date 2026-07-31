import java.util.*; 

 
class Solution {
    
    class Result{
        int length; int startIdx;
        public Result(int length, int startIdx){
            this.length = length; this.startIdx = startIdx; 
        }
    }
    
    public int[] solution(int[] sequence, int k) {
        
        List<Result> res = new ArrayList<>(); 
        
        
        // 투포인터로 합 계산
        int sum = sequence[0]; // left ~ right 까지의 합
        int left = 0; int right = 0; 
        while(right < sequence.length){
            if(sum < k){
                right++;
                if(right < sequence.length) {
                    sum += sequence[right]; 
                }
            }else if(sum > k){
                sum -= sequence[left]; 
                left++;
            }else{
                res.add(new Result(right-left+1, left));
                
                sum -= sequence[left]; 
                left++;
            }
        }
        
        res.sort((a, b) -> {
            if(a.length != b.length) return Integer.compare(a.length, b.length);
            else return Integer.compare(a.startIdx, b.startIdx);
        }); 
        
        // 부분 수열의 시작 인덱스, 마지막 인덱스
        return new int[]{res.get(0).startIdx, res.get(0).startIdx+res.get(0).length-1};
    }
}