#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int timeToMin(string time){
    int hour = stoi(time.substr(0, 2)); 
    int min = stoi(time.substr(3, 2)); 
    
    return hour*60 + min;
}
string minToTime(int time){
    int h = time / 60;
    int m = time % 60;
    
    string hour = to_string(h);
    string min = to_string(m);
    
    if (hour.length() == 1) hour = "0" + hour;
    if (min.length() == 1) min = "0" + min;
    
    return hour + ":" + min;
}

// 09:00부터 n회 t분 간격으로 역에 도착. 최대 m명의 승객이 탈 수 있음
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    // 크루들 도착 시간
    vector<int> crewTime; 
    for(auto& t: timetable){
        crewTime.push_back(timeToMin(t));
    }
    sort(crewTime.begin(), crewTime.end());
    // 버스 도착 시간 배열에 넣기
    vector<int> busTime;
    for(int i = 0; i <= (n-1)*t; i+=t){
        busTime.push_back(9*60 + i); 
    }
    
    // 버스 도착 시간 되면 m명만큼 사람 보내기 -> n*m = 450
    int currId = 0;
    int max = 23*60 + 59;
    int lastNum = 0;
    for(int i = 0; i < busTime.size(); i++){ // 10
        if(crewTime.size() <= currId) break;
        // 버스 시간에 m명씩 보내기
        for(int j = 0; j < m; j++){ // 45
            if(crewTime.size() <= currId) break;
            if(crewTime[currId] > busTime[i]) break;
            
            if(i == (busTime.size()-1)){
                max = crewTime[currId];
                lastNum++; // 막차의 승객 명수
            }
            
            // 태우고 다음 승객이 첫번째로 기다리는 승객이 됨
            currId++; 
        }
    }
    
    // 마지막에 자리가 남았으면 막차 도착 시간에 넣기
    if(lastNum < m){
        answer = minToTime(9*60 + t*(n-1));
        // cout << 1 << " " << lastNum << endl;
    }
    // 자리가 안남았으면 max-1로
    else{
        answer = minToTime(max-1);
        // cout << 2 << " " << minToTime(max-1) << endl;
    }
    
    
    // 콘이 셔틀을 타고 사무실로 갈 수 있는 도착 시각 중 제일 늦은 시각
    return answer;
}