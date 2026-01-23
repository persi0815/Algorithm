#include <string>
#include <vector>
#include <iostream> 

using namespace std;
/*
o(n)으로 앞부터 쭉 돌면서 빈칸인지, 대문자인지 소문자인지 확인

빈칸이면, 다음을 대문자로 만들어야. 그런데 숫자가 나오면 지나감. 

빈칸이 아니었으면 대문자 -> 소문자. 숫자 -> 그대로. 

대문자 소문자 비교는

*/
bool isBlank = true;
char res;

string solution(string s) {
    string answer = "";
    
    for(int i = 0; i < s.length(); i++){
        if(isBlank == true){ // 이전에 빈칸 -> 대문자 or 숫자
            if(49 <= s[i]-'0' && s[i]-'0' <= 74){ // 소문자 -> 대문자
                res = s[i]-32;
                answer += res;
                isBlank = false; // 첫 글자 끝남 표시
            }
            else if (s[i] == ' ') { // 빈칸 -> 출력하고 표시 (공백 연속)
                answer += s[i];
            }
            else {
                answer += s[i]; // 대문자, 숫자 -> 그대로
                isBlank = false; // 첫 글자 끝남 표시
            }
            
        }
        
        else { // 이전에 빈칸 아님 -> 소문자
            if(17 <= s[i]-'0' && s[i]-'0' <= 42){ // 대문자 -> 소문자
                res = s[i]+32;
                answer += res;
            }
            else if(s[i] == ' ') { // 빈칸 -> 출력하고 표시
                isBlank = true;
                answer += s[i];
            }
            else answer += s[i]; // 숫자 -> 그대로
        }
    }
    
    return answer;
}

// 대문자 17~42, 소문자 49~74, 숫자는 그대로 나옴