#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;
vector<vector<int>> candidate;

unordered_set<int> unit;
void makeUnit(int num, int id, int size){
    if(id == size){
        unit.insert(num); 
        return;
    }
    vector<int> candi = candidate[id];
    for(int i = 0; i < candi.size(); i++){ // candi 중 하나 고르면 됨. 이전에 안나왔던 것중에
        if((num & (1 << candi[i])) != (1 << candi[i])){
            makeUnit(num|(1 << candi[i]), id+1, size);
        }
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    // 각 user에 번호 매기기. 0번~
    unordered_map<string, int> user; 
    for(int i = 0; i < user_id.size(); i++){
        user[user_id[i]] = i;
    }
    
    // 각 banned_id가 가능한 id 조합 구하기 -> vector에 넣기
    candidate.assign(banned_id.size(), vector<int>());
    for(int j = 0; j < banned_id.size(); j++){
        string b = banned_id[j];
        // 유저 돌며 맞는 id 찾아서 번호 넣기
        for(auto& u: user_id){
            bool avail = true;
            if(u.size() == b.size()){
                for(int i = 0; i < u.size(); i++){
                    if(b[i] != '*' && b[i] != u[i]){
                        avail = false; break;
                    }
                }
                if(avail) {
                    candidate[j].push_back(user[u]);
                }
            }
        }
    }
    
    // 하나씩 돌면서 기존의 id와 겹치지 않는 id 선택 -> set에 넣기
    makeUnit(0, 0, banned_id.size());
    
    // 당첨에서 제외되어야 할 제재 아이디 목록은 몇가지 경우의 수가 가능한 지
    return unit.size();
}