#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    // 크기:개수 o(n)
    unordered_map<int, int> size_cnt;
    for(int i = 0; i < tangerine.size(); i++){
        size_cnt[tangerine[i]]++;
    }
    
    // 개수 내림차순 o(nlogn)
    vector<int> nums;
    for(auto& m: size_cnt){
        nums.push_back(m.second);
    }
    
    // 내림차순 정렬
    sort(nums.begin(), nums.end(), greater<int>());
    
    for(int i = 0; i < nums.size(); i++){
        if(k <= 0) break;
        else{
            k-= nums[i];
            answer = i+1;
        }
    }
    
    
    return answer; // k개를 고를 때 크기가 서로 다른 종류의 수의 최솟값
}