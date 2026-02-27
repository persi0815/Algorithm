#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    
    for(auto& s: skill_trees){
        vector<int> n(26, INT_MAX); bool avail = true;
        // 하나씩 돌며 스킬들 인덱스 추출
       for(int i = 0; i < s.size(); i++){
            n[s[i]-'A'] = i;
        } 
        
        // 순서 맞는지 확인
        int m = -1;
        for(int i = 0; i < skill.size(); i++){
            if(n[skill[i]-'A'] >= m) m = n[skill[i]-'A']; 
            else {
                avail = false; break; 
            }
        }
        if(avail) {
            answer++;
        }
        
    }
    
    return answer;
}