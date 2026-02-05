#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> nums;
    
    // 집합 추출
    vector<int> set;
    int num = 0;
    for(int i = 1; i < s.size()-1; i++){
        if(s[i] == '}'){
            set.push_back(num); num = 0; 
            nums.push_back(set); set.clear(); 
        }else if (s[i] == ',' && num != 0){
            set.push_back(num); num = 0; 
        }else if('0' <= s[i] && s[i]  <= '9'){ // 수라면
            num = num*10 + s[i] - '0';
        } 
    }
    
    // 크기 순으로 정렬
    sort(nums.begin(), nums.end(), [](auto &a, auto &b){
         return a.size() < b.size();
    });
    
    // 차례대로 만들기
    unordered_set<int> uni;
    for(int i = 0; i < nums.size(); i++){
        for(int& n : nums[i]){
            if(!uni.count(n)) {
                answer.push_back(n); uni.insert(n);
            }
        }
    }
    
    return answer; // s가 포함하는 튜플을 배열에 담기
}