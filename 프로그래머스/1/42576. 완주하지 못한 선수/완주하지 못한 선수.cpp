#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// 참여한 선수들의 이름 배열, 완주한 선수들의 이름 배열
string solution(vector<string> participant, vector<string> completion) {
    string answer = ""; // 완주하지 못한 선수의 이름 (한명)
    
    unordered_map<string, int> m;
    for(string part: participant){
        m[part]++;
    }
    
    for(string comp: completion){
        m[comp]--;
    }
    
    for(auto mm: m){
        if(mm.second != 0) answer = mm.first;
    }
    
    return answer;
}