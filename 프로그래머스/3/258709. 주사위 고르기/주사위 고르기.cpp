#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
/*
주사위 고름 -> 승패, 무승부 모두 기록 -> 승이 가장 많은 거 골라 진행
1. 조합으로 주사위 골라
2. 완탐으로 각 상황에 이길지 질지 무승부인지 기록
3. 승이 가장 많은거 골라 답 입력
*/


vector<vector<int>> combinations(int num){
    vector<vector<int>> combination;
    vector<int> dice_num(num);
    for(int i = 1; i <= num; i++){
        dice_num[i-1] = i;
    }
    vector<bool> select(num, false);
    fill(select.end() - num/2, select.end(), true);
    
    
    do{
        vector<int> comb;
        for(int j = 0; j < num; j++){
            if(select[j] == true) comb.push_back(dice_num[j]); 
        }
        combination.push_back(comb);
        
    } while(next_permutation(select.begin(), select.end()));
    
    return combination;
}

void find_sums(const vector<int> &dice_nums, const vector<vector<int>> &nums, int depth ,int sum, unordered_map<int, int>& sums){
    if(depth == nums.size()/2){
        sums[sum]++;
        //cout << sum << " " << sums[sum] << endl;
        return;
    }
    
    for(int i = 0; i < 6; i++){
        find_sums(dice_nums, nums, depth+1, sum + nums[dice_nums[depth] - 1][i], sums);
    }
    
}

int win_count(vector<int> &a, vector<vector<int>> &dice){ // a가 선택한거
    int win = 0;
    vector<int> b;
    for(int i = 1; i <= dice.size(); i++){
        if(find(a.begin(), a.end(), i) == a.end()) b.push_back(i);
    }
    
    // a 가능한 합들, b 가능한 합들 전부 개수까지 구해서
    unordered_map<int, int> a_sum; // 합, 개수
    unordered_map<int, int> b_sum; 
    //cout << "a================================" << endl;
    find_sums(a, dice, 0, 0, a_sum);
    //cout << "b================================" << endl;
    find_sums(b, dice, 0, 0, b_sum);
    
    for(auto a: a_sum){
        for(auto b : b_sum){
            if(a.first > b.first) win += (a.second * b.second);
        }
    }
    
    
    return win;
}

vector<int> solution(vector<vector<int>> dice) { // 주사위의 수의 구성이 담겨있음
    vector<int> answer;
    priority_queue<pair<int, vector<int>>> res; // 이긴 개수, 주사위 번호
    
    // 조합으로 주사위 고르기
    vector<vector<int>> combination = combinations(dice.size()); // 개수 넣음
    
    // 해당 조합에서 승리하는 횟수 구해서 저장
    for(auto &comb : combination){
        res.push({win_count(comb, dice), comb});
    }
    
    // 승이 가장 많은거 top 주사위 기록
    auto ans = res.top().second;
    for(int & num: ans){
        answer.push_back(num);
    }
    
    return answer; // a가 가져가야 하는 주사의 번호를 오름차순으로 넣자. 
}