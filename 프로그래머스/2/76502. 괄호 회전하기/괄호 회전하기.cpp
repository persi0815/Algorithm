#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;
vector<pair<int, int>> pairs = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
bool check(queue<char> q){ // 그냥 복사해오기
    stack<char> s; 
    int size = q.size();
    for(int i = 0; i < size; i++){
        // 여는거면 넣고, 빼는거면 제거
        char qf = q.front(); q.pop();
        // 여는 괄호라면
        if(qf == '(' || qf == '[' || qf == '{') {
            s.push(qf);
        } 
        // 닫는 괄호라면
        else{
            for(int i = 0; i < 3; i++){
                if(qf == pairs[i].second){
                    if(s.empty()) { return false;}
                    else if (s.top() == pairs[i].first) { s.pop();}
                    else {s.push(qf);} 
                }
            }
        }
    }
    if(s.empty()) return true;
    else return false;
}

int solution(string s) {
    int answer = 0;
    int size = s.size();
    
    // 큐에 넣기
    queue<char> q;
    for(int i = 0; i < size; i++){
        q.push(s[i]);
    }
    if(check(q)) answer++;
    
    // 회전시키고 확인 반복
    for(int i = 0; i < size-1; i++){
        q.push(q.front());
        q.pop();
        if(check(q)) answer++;
    }

    return answer;
}