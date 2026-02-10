#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    // 각 유저별로 신고된 횟수
    unordered_map<string, int> times; // 신고당한 횟수
    unordered_map<string, unordered_set<string>> reports; // {누가를: 누구가}
    for(string& r: report){
        string from, to;
        stringstream ss(r);
        ss >> from >> to; 
        if(!reports[to].count(from)) times[to]++;
        reports[to].insert(from); 
    }
    
    // 각 유저별로 정지된 사람을 신고한 횟수 정리
    unordered_map<string, int> res; // {누가, 신고한 사람 중 정지먹은 사람수}
    for(auto& t: times){
        if(t.second >= k){
            // 그 사람을 신고한 사람들 횟수 늘리기
            for(const string& p: reports[t.first]){
                res[p]++;
            }
        }
    }
    
    // 각 유저별로 처리 결과 메일을 받은 횟수
    for(string& id: id_list){
        answer.push_back(res[id]);
    }
    return answer;
}