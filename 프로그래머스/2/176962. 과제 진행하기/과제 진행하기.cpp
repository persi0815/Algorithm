#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// "HH:MM" -> 분(int)으로 변환
int timeToMin(string t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    // 각 행의 [1]번째 원소(시간)를 비교하여 오름차순 정렬
    sort(plans.begin(), plans.end(), [](const vector<string>& a, const vector<string>& b) {
        return a[1] < b[1];
    });
    
    // 작업 순회하며 실행
    stack<pair<string, int>> stopped; // {과제명, 남은 시간}
    int curTime = 0;
    
    for(int i = 0; i < plans.size(); i++){
        int startTime = timeToMin(plans[i][1]);
        int planDuration = stoi(plans[i][2]);
        
        // 다음 작업까지 시간 남음 -> 가장 최신에 마무리 못했던 작업 실행
        while(curTime < startTime){ 
            if(!stopped.empty()){
                auto& top = stopped.top(); // name, duration
                int timeDiff = startTime - curTime; // 남은 시간

                // 시간 부족하면 stack에 넣기
                if(top.second > timeDiff){
                    top.second -= timeDiff;
                    curTime = startTime;
                }else{ // 시간 안에 끝낼 수 있음
                    answer.push_back(top.first);
                    stopped.pop();
                    curTime += top.second;
                }
            } else{ // 작업 남은게 없으면
                curTime = startTime;
            }
            
        }
        
        // 현재 과제 시작
        curTime = startTime;
        string planName = plans[i][0];
        if(i < plans.size()-1){ // 마지막이 아니면
            int nextStartTime = timeToMin(plans[i+1][1]);
        
            if(curTime + planDuration > nextStartTime){ // 작업 다 못 끝냄
                stopped.push({planName, curTime + planDuration - nextStartTime});
                curTime = nextStartTime;
            }
            else{ // 작업 끝
                answer.push_back(planName);
                curTime += planDuration;
            }
        } else{ // 마지막 과제면 그냥 끝내버리기
            answer.push_back(planName);
            curTime += planDuration;
        }
    }
    
    // 순회 전부 끝나고 남은 작업 있다면 실행
    while(!stopped.empty()){
        answer.push_back(stopped.top().first); 
        stopped.pop();
    }
    
    
    return answer; // 과제를 끝낸 순서대로 이름 담기
}