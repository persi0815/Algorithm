import java.util.*; 
/*
연산 순서에 따라 결과가 바뀜. 문자열 형태의 숫자와 기호가 들어가있는 배열이 주어짐. 
서로 다른 연산 순서의 계산 결과 중 최댓값 구하기
-> 부분 구간에서 만들 수 있는 최댓값/최솟값 구하기.
완탐 안됨. O(!100)

*/

class Solution {
    
    public int solution(String arr[]) {
        int num_cnt = (arr.length + 1)/2;
        
        int[][] maxDp = new int[num_cnt][num_cnt]; // maxDp[시작][끝] = 최댓값
        int[][] minDp = new int[num_cnt][num_cnt]; // minDp[시작][끝] = 최솟값
        // 초기화
        for (int i = 0; i < num_cnt; i++) {
            int val = Integer.parseInt(arr[i * 2]);
            maxDp[i][i] = val;
            minDp[i][i] = val;
        }

        
        for(int len = 1; len < num_cnt; len++){ // 부분 구간 길이
            for(int st = 0; st + len < num_cnt; st++){ // 부분 구간 시작 지점. 끝까지 범위 고려!
                int ed = st + len;
                maxDp[st][ed] = Integer.MIN_VALUE; // 나머지 갱신전 초기화
                minDp[st][ed] = Integer.MAX_VALUE;
                
                for(int cut = st; cut < ed; cut++){ // 끊기는 자리
                    String order = arr[cut*2+1];
                    if(order.equals("+")){
                        maxDp[st][ed] = Math.max(maxDp[st][ed], 
                             maxDp[st][cut] + maxDp[cut+1][ed]);
                        minDp[st][ed] = Math.min(minDp[st][ed], 
                             minDp[st][cut] + minDp[cut+1][ed]);
                        //System.out.println(st + " " + ed+ " " + maxDp[st][ed] + " " + minDp[st][ed]);
                    }else if(order.equals("-")){
                        maxDp[st][ed] = Math.max(maxDp[st][ed], 
                             maxDp[st][cut] - minDp[cut+1][ed]);
                        minDp[st][ed] = Math.min(minDp[st][ed], 
                             minDp[st][cut] - maxDp[cut+1][ed]);
                        //System.out.println(st + " " + ed+ " " + maxDp[st][ed] + " " + minDp[st][ed]);
                    }
                }
            }
        }
        
        return maxDp[0][num_cnt-1];
    }
}