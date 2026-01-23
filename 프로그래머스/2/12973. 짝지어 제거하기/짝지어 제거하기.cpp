#include <iostream>
#include<string>
#include <stack>
using namespace std;

// 항상 처음으로 돌아와서 다시 계산
int answer = 0;

int solution(string s)
{
    stack<int> st; 
    
    for(int i = 0; i < s.size(); i++){
        if(st.empty()) st.push(s[i]);
        else{
            if(st.top() == s[i]) st.pop(); 
            else st.push(s[i]);
        }
    }
    
    if(st.empty()) answer = 1;
    
    return answer;
}