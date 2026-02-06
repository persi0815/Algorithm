#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// 닉네임을 변경한 기록
vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> nickname; // {id, nickname}
    
    vector<pair<string, string>> log; // order, id
    for(string& r: record){
        string order, id, nick;
        stringstream ss(r);
        ss >> order >> id;
        
        if(order == "Enter" || order == "Leave"){
            log.push_back({order, id});
        }
        if(order == "Enter" || order == "Change"){
            ss >> nick;
            nickname[id] = nick;
        }
    }
    
    // 로그로 메시지 만들기(id 확인)
    for(auto & l: log){// order, id
        string id = l.second;
        if(l.first == "Enter"){
            answer.push_back(nickname[id] + "님이 들어왔습니다.");
        } else if(l.first == "Leave"){
            answer.push_back(nickname[id] + "님이 나갔습니다.");
        }
    }
    
    // 최종적으로 방을 개설한 사람이 보게되는 메시지
    return answer;
}