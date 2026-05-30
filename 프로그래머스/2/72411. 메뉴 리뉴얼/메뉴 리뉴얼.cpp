#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

// 각 손님들이 주문한 단품 메뉴들, 추가하고 싶은 메뉴들의 갯수
vector<string> solution(vector<string> orders, vector<int> course) {
    
    // 먼저 코스들 bit로 표시
    vector<int> orders_bit; 
    for(auto o : orders){
        int b = 0; 
        for(auto c : o){
            b |= 1 << (c-'A');  // 'A'를 1로, 'B'를 10으로 표현
        }
        orders_bit.push_back(b);
    }
    
    // 겹치는 거 candidates에 넣기
    unordered_map<int, int> candidates; // 메뉴 구성 후보들, 개수
    for (int a = 0; a < orders_bit.size(); a++) {
        int mask = orders_bit[a];

        // 이 손님이 가질 수 있는 모든 부분집합을 구해서 맵에 +1
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            candidates[submask]++;
        }
    }
    
    
    // candidates에서 숫자 가지고 알파벳으로 변환
    vector<pair<string, int>> ans;
    for(auto c : candidates){
        if(c.second < 2) continue;
        string alph = "";
        for(int i = 0; i < 26; i++){
            if(1 << i & c.first) alph += 'A' + i;
        }
        ans.push_back({alph, c.second}); 
    }
    
    // 크기가 course 개수인 것만 남기기
    vector<string> answer;
    sort(ans.begin(), ans.end(), [](const auto &a, const auto &b){
        if(a.first.size() != b.first.size()) return a.first.size() < b.first.size(); 
        else if(a.second != b.second) return a.second > b.second; 
    });
    int cid = 0; int max_cnt = 0; 
    for(auto a : ans){
        // 크기가 corse[cid] 보다 작거나 같을때까지
        while(a.first.size() > course[cid]){
            cid ++; 
            max_cnt = 0; // 초기화
        }
        if(a.first.size() == course[cid]) {
            if(max_cnt <= a.second){
                max_cnt = a.second; // 갱신
                answer.push_back(a.first); 
                // cout << a.first << " " << a.second << endl;
            }
        }
    }
    
    // 새로 추가하게 될 코스요리의 메뉴들 정렬
    sort(answer.begin(), answer.end()); // 사전순 오름차순 정렬 
    
    return answer;
}