#include <iostream>
#include <string>
#include <vector>
#include <string>
using namespace std;
/*
k개의 수 제거 -> 얻을 수 있는 가장 큰 수
*/ 

string solution(string number, int k) {
    string answer = "";
    
    int siz = number.size() - k; // 구해야 하는 수의 자릿수
    int end = -1; 
    
    for(int i = siz; i > 0; i--){ // 각 자릿수
        int nn = -1; int idx = -1; 
        
        for(int s = number.size() - i; s > end; s--){
            // 가능한 곳부터 나왔던 수보다 뒤쪽에 있는 수 선택
            int num = number[s] - '0';
            //cout << "s: " << s << endl;
            if(nn <= num){
                nn = num;
                //cout << nn << endl;
                idx = s;
                
            }
        }
        end = idx;
        answer += to_string(nn);
        
    }
    
    return answer;
}