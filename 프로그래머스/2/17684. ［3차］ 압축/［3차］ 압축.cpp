#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    // 기본 색인 만들기
    unordered_map<string, int> alphaNum;
    for(int i = 0; i < 26; i++){
        char c = 'A'+i;
        alphaNum[string(c, 1)] = i+1;
    }
    
    // 현재입력부터 다음꺼까지 사전에 있으면 가장 큰거 사용, 없으면 사전 추가
    for(int w = 0; w < msg.size(); w++){
        string now = string(msg[w], 1);
        char next = msg[w+1];
        // 있으면 더 큰거 확인
        while(alphaNum.find(now) != alphaNum.end()){
            now += next; w++;
            next = msg[w+1];
        }
        w--;
        // 없는거 등록
        alphaNum[now] = alphaNum.size()+1; 
        // 현재꺼 색인 출력
        answer.push_back(alphaNum[now.substr(0, now.size()-1)]);
    }
    
    
    // 주어진 문자열을 압축한 후의 사전 색인 번호를 배열로 출력
    return answer;
}