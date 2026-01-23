#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/*
n을 2진수로 바꾸고 해당 2진수에서
처음으로 0이 아닌 수를 1로(이전에 1이 있어야 함), 0 위치의 이전중 가장 최신의 1값을 0으로
-> 최소한 조금 더하기 => 가장 작은 수
*/

int solution(int m) {
    int answer = 0;
    
    // n을 2진수로 바꾸기. 왼쪽부터 작은 자리
    vector<int> binary; 
    int n = m;
    while(n > 1){
        binary.push_back(n % 2); 
        n /= 2;
    }
    binary.push_back(1); 
    
    // 돌면서 '10' 찾기
    bool one_passed = false; 
    int one_cnt = -1; // biggest_one_id 아래의 1개수
    int biggest_one_id = -1;
    for(int i = 0; i < binary.size(); i++){ // 10 찾기
        // 1이 없으면 계속 1 찾기
        if(!one_passed){
            if(binary[i] != 1) continue; 
            else {
                one_passed = true;
                biggest_one_id = i;
                one_cnt++;
            }
        }
        // 1이 지났으면 0 나오길 기다림
        else{
            if(binary[i] == 1){
                biggest_one_id = i;
                one_cnt++;
            }
            else{ // 첫 0    
                break;
            }
        }   
    }
    
    // 값 한번 갱신
    answer = m - pow(2, biggest_one_id) + pow(2, biggest_one_id+1); // 86
//     cout << answer << " " << biggest_one_id << " " << pow(2, biggest_one_id);

//     cout << "cnt: " << one_cnt << endl;
    
    // 1 가장 작은 곳으로 보내기
    for(int i = 0; i < biggest_one_id; i++){
        if(i < one_cnt) {
            // 0이었다면 1로
            if(binary[i] == 0) answer += pow(2, i);
        }
        else {
            // 1이었다면 0으로
            if(binary[i] == 1) answer -= pow(2, i);
        }
        
    }

    
    return answer;
}