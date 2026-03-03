#include <string>
#include <vector>

using namespace std;

int timeToSec(string time){
    int hour = stoi(time.substr(0, 2)); 
    int min = stoi(time.substr(3, 2)); 
    int sec = stoi(time.substr(6, 2));
    return hour*60*60 + min*60 + sec; 
}

string secToTime(int time){
    string sec = to_string(time % 60); time /= 60;
    string min = to_string(time % 60); time /= 60;
    string hour = to_string(time);
    if(sec.length() < 2) sec = "0" + sec; 
    if(min.length() < 2) min = "0" + min; 
    if(hour.length() < 2) hour = "0" + hour; 
    return (hour) + ":" + (min) + ":" + (sec); 
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    // logs 돌며 각 사용자 시청 시각 기록하기
    int playTime = timeToSec(play_time);
    vector<int> play(playTime+1, 0); 
    for(auto& l: logs){
        string start = l.substr(0, 8); 
        string end = l.substr(9, 8);
        play[timeToSec(start)] ++;
        play[timeToSec(end)] --;
    }
    
    // 누적합 만들기
    vector<int> prefixSum(playTime+1, 0); 
    prefixSum[0] = play[0];
    for(int i = 1; i < play.size(); i++){
        prefixSum[i] = prefixSum[i-1] + play[i];
    }
    
    // sliding window로 누적 재생시간 합 구하고 더 커질때 갱신
    int advTime = timeToSec(adv_time); 
    long long playTimeSum = 0; int startTime = 0;
    for(int i = 0; i < advTime; i++){
        playTimeSum += prefixSum[i]; 
    }
    long long newSum = playTimeSum;
    for(int i = advTime; i < playTime; i++){
        newSum = newSum + prefixSum[i] - prefixSum[i-advTime];
        if(newSum > playTimeSum){
            playTimeSum = newSum;
            startTime = i - advTime + 1;
        };
    }
    
    // 공익광고가 들어갈 시작 시각 리턴. 가장 빠른 시작 시각
    return answer = secToTime(startTime);
}