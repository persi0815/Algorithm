#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long solution(string expression) { // 연산 수식이 담긴 문자열
    long long answer = 0;
    
    // expression에서 수와 연산자 분리 (string) 
    vector<string> express; 
    string num = "";
    for(char c : expression){ // 300
        if(isdigit(c)){
            num += c;
        }else{
            express.push_back(num); num = "";
            express.push_back(string(1, c));
        }
    }
    express.push_back(num); // 마지막 숫자
    
    // 우선순위 정하기(+, -, *)
    vector<int> p = {0, 1, 2};
    vector<string> ops = {"+", "-", "*"};
    
    do{ // 해당 우선순위 연산자로 연산
        vector<string> temp_express = express; // 매 순열마다 원본에서 다시 시작
        
        // 이번 차례 연산자로 연산
        for(int j = 0; j < 3; j++){
            string current_op = ops[p[j]]; 
            vector<string> progress; // 중간 과정
            
            // 연산 (연산자, 수) 이렇게 묶어서 두개씩 처리
            progress.push_back(temp_express[0]);
            for(int i = 1; i < temp_express.size()-1; i+=2){
                if(temp_express[i] != current_op){ // 해당 연산자 아니면 그냥 넣기
                   progress.push_back(temp_express[i]); 
                   progress.push_back(temp_express[i+1]); 
                }else{ // 해당 연산자면 연산해 넣기
                    long long first = stoll(progress.back()); 
                    long long second = stoll(temp_express[i+1]);
                    long long num = 0;
                    if(current_op == "+") num = first + second; 
                    else if(current_op == "-") num = first - second; 
                    else num = first * second; 

                    progress.pop_back(); 
                    progress.push_back(to_string(num));
                }
            } 
            temp_express = progress; // 연산자 결과 저장
            
        }
        // 해당 우선순위의 결과 저장
        answer = max(answer, abs(stoll(temp_express[0])));

    }while(next_permutation(p.begin(), p.end()));

    
    return answer;
}