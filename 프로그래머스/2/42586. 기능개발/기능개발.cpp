#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
/*
진도가 100%일때 서비스에 반영 가능
뒤의꺼가 앞보다 먼저 개발되면, 뒤와 앞이 함께 배포
=> 몇개의 기능이 배포되나? 
*/

// 배포되어야 하는 순서대로 작업의 진도가 적힙
// 각 작업의 개발 속도가 적힌 정수 배열
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days_left;

    int siz = progresses.size();
    for(int i = 0; i < siz; i++){
        int left = 100 - progresses[i]; 
        int days = (left % speeds[i] == 0) ? left / speeds[i] : left / speeds[i] + 1; 
        days_left.push_back(days); 
    }

    int current = days_left[0];
    int count = 1;
    
    for(int i = 1; i < days_left.size(); i++) {
        if (days_left[i] <= current) {
            count++; // 같이 배포 가능
        } else {
            answer.push_back(count); // 지금까지 쌓인 거 배포
            current = days_left[i]; // 새로운 배포 시작 기준
            count = 1;
        }
    }
    answer.push_back(count); // 마지막 남은 거 배포

    return answer;
}
