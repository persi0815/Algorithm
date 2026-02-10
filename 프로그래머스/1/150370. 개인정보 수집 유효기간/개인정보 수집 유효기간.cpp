#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int cal(string date){
    stringstream ss(date);
    string y, m, d;
    getline(ss, y, '.');
    getline(ss, m, '.');
    getline(ss, d, '.');
    return stoi(y)*12*28 + stoi(m)*28 + stoi(d);
}

// terms의 원소는 "약관 종류 유효기간(달)"
// privacies[i]는 i+1번 개인정보의 수집 일자와 약관 종류
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int todayDate = cal(today);
    unordered_map<char, int> term; 
    for(auto& t: terms){
        term[t[0]] = stoi(t.substr(2)); // 달의 단위가 세자릿 수 이상일 수 있음..!
    }
    
    // privacies 돌며 오늘로 유효기간 지났는지 확인 -> 인덱스 + 1인 번호 넣기
    for(int i = 0; i < privacies.size(); i++){
        string date = privacies[i].substr(0, 10); 
        char t = privacies[i][11];
        int startDate = cal(date); 
        // term에 맞춰 date 갱신
        int endDate = startDate + term[t]*28;
        // 오늘부터 파기 가능하면 넣기
        if(todayDate >= endDate) answer.push_back(i+1);
    }
    
    // 오늘 날짜로 파기해야 할 개인정보 번호들을 오름차순으로 리턴
    sort(answer.begin(), answer.end());
    return answer;
}