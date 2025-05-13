#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
/*
탐색 -> 완탐/이진탐색
*/

int binary_search(int left, int right, const vector<int>& diffs, const vector<int>& times, const long long& limit){
    int ans = INT_MAX; // 숙련도
    
    while(left <= right){
        int level = (left + right)/2; 
        long long time = 0; 
        
        // 모든 퍼즐 해결하기
        for(int i = 0; i < diffs.size(); i++){
            if(diffs[i] <= level) time += times[i]; 
            else{
                time += 
                    (times[i] + times[i-1]) * (diffs[i] - level) + times[i];
                // 걸리는 시간 * 틀리는 횟수 + 다시 푸는 시간
            }
            
            if(time > limit) break; // 넘으면 더 이상 볼 것도 없음
        }
        
        if(time > limit) left = level + 1; // 오래 걸리니 숙련도 높여
        else if(time <= limit) {
            right = level - 1; // 짧게 걸리니 숙련도 낮춰
            ans = min(ans, level); 
        }
    }
    
    return ans;
}

// 퍼즐의 난이도, 퍼즐의 소요시간, 전체 제한 시간
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0; 
    // 제한 시간 내에 퍼즐을 모두 해결하기 위한 숙련도의 최솟값 
    
    int st = *min_element(diffs.begin(), diffs.end()); 
    // 최소 첫 문제는 풀어야 하기에
    int en = *max_element(diffs.begin(), diffs.end());
    
    answer = binary_search(st, en, diffs, times, limit); 
    
    
    return answer;
}