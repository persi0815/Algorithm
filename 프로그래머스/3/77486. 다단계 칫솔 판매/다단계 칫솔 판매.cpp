#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cmath>

using namespace std;

void share(unordered_map<string, string>& enrollBy, unordered_map<string, int>& money, string seller, int price){
    // 자신은 90% 갖고 넘김
    if(((double)price / 10) < 1) {
        money[seller] += price; 
    }
    else{
        money[seller] += (int)(ceil((double)price * 9 / 10)); 
        if(enrollBy[seller] != "-") share(enrollBy, money, enrollBy[seller], (int)floor(price / 10));
    } 
}

// 각 판매원의 이름을 담은 배열 enroll
// 각 판매원을 다단계 조직에 참여시킨 다른 판매원의 이름을 담은 배열 referral
// 판매량 집계 데이터의 판매원 이름을 나열한 배열 seller
// 판매량 집계 데이터의 판매 수량을 나열한 배열 amount
vector<int> solution(vector<string> enroll, vector<string> referral, 
                     vector<string> seller, vector<int> amount) {
    // 연결리스트 만들기
    unordered_map<string, string> enrollBy; // {누가, 누구에게}
    for(int i = 0; i < enroll.size(); i++){
        enrollBy[enroll[i]] = referral[i];
    }
    
    // 각 이익 분배 - 이익은 개당 100 원
    unordered_map<string, int> money; // {누가, 얼마}
    for(int i = 0; i < seller.size(); i++){
        share(enrollBy, money, seller[i], amount[i]*100);
    }
    
    // 배분된 이익금의 총합을 enroll 순서에 따라 나열
    vector<int> answer;
    for(auto& e : enroll){
        answer.push_back(money[e]);
    }
    return answer;
}