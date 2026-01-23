#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
vector<int> answer;
int change_num = 0;
int zero_num = 0;
/*
0 제거 -> 길이 구하기 -> 2진법으로 만들기
반복해서 s가 1이 될 때까지 반복
*/

string make_binary(string s){
    // 돌며 0 제거
    int one_count = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') one_count++;
    }
    zero_num += (s.size()-one_count);
    // cout << zero_num << " ";
        
    // count 값을 2진법으로 만들기
    stack<int> st;
    while(one_count != 1){
        st.push(one_count % 2); 
        one_count /= 2;
    }
    string res = "1";
    int st_size = st.size();
    for(int i = 0; i < st_size; i++){
        res += to_string(st.top()); 
        st.pop();
    }
    
    change_num++;
    // cout << res << endl;
    
    return res;
}

vector<int> solution(string s) {
    if(s == "1"){
        return {0, 0};
    }
    
    while(true) {
        s = make_binary(s);
        if(s == "1" || s.size() == 1) break;
    }

    return answer = {change_num, zero_num};
}