#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=1;

    // 중심부분에서부터 나아가기
    for(int i = 1; i < s.size(); i++){ // 2500
        int len = 1;
        // 길이가 짝수라면
        if(s[i] == s[i-1]){
            answer = max(answer, 2);
            while(i-1-len >= 0 && i+len < s.size()){
                if(s[i-1-len] == s[i+len]){
                    answer = max(answer, len*2+2); len++; 
                }else break;
            }
        }
        len = 1;
        // 길이가 홀수라면
        while(i-len >= 0 && i+len < s.size()){
            if(s[i-len] == s[i+len]){
                answer = max(answer, len*2+1); len++; 
            }else break;
        }
        
    }

    // s의 부분문자열(Substring)중 가장 긴 팰린드롬의 길이를 return
    return answer ;
}