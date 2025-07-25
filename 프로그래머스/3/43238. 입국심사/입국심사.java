import java.util.*; 
/*
n명이 기다리고 있음. 한 심사대에서는 동시에 한 명만 심사 가능. 심사관마다 심사하는 데에 걸리는 시간이 다 다름
가장 앞에 서 있는 사람은 비어 있는 곳에 가서 받을 수 있는데, 더 빨리 끝나는 심사대가 있으면 기다렸다가 그곳으로 가서 심사 받을 수도 있다. 
모든 사람이 심사 받는 데에 걸리는 시간을 최소로 하고 싶다. 
*/

class Solution {
    
    // 심사 기다리는 사람 수, 각 심사관이 한 명을 심사하는 데에 걸리는 시간
    public long solution(int n, int[] times) {
        long answer = Long.MAX_VALUE; // 모든 사람이 심사 받는데에 걸리는 시간의 최솟값 리턴
        int judge = times.length;
        Arrays.sort(times); // 오름차순 정렬
        
        // 이분 탐색
        long right = (long) n * times[judge - 1]; 
        long left = 1;
        
        while(left <= right){
            long mid = (right + left)/2; // 소요시간
            long num = n;
            boolean can = false;
            for(int time: times){
                long handle = mid/time; // 주어진 시간 동안 처리할 수 있는 명수
                num -= handle; // 명수 제거하기
                if(num <= 0) { // 다 처리했다면 끝
                    can = true; break;
                }
            }
            
            if(can){
                right = mid - 1;
                answer = Math.min(mid, answer);
                //System.out.println(mid);
            }else{
                left = mid + 1;
            }
            
            
        }
        
        
        return answer;
    }
}