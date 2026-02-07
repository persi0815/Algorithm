#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0; // 불가능하면 -1 리턴
    queue<int> q1; queue<int> q2;
    
    // 현재 두 배열의 차이
    long long diff = 0;
    for(int & q: queue1){
        diff += q; q1.push(q);
    }
    for(int & q: queue2){
        diff -= q; q2.push(q);
    }
    diff /= 2;
    // cout << "diff: " << diff << endl;
    
    // q1-q2가 diff가 될때까지
    long long d = 0; bool avail = false;
    while(answer <= (queue1.size() + queue2.size())*2){
        if(d < diff){
            d += (q1.front()); q2.push(q1.front()); q1.pop();
            // cout << " " << d << endl;
        }else if(d > diff){
            d-= (q2.front()); q1.push(q2.front()); q2.pop();
            // cout << " " << d << endl;
        }else {
            avail = true; break;
        }
        answer++;
    }
    
    
    // 각 큐의 원소합 같게 만들기 위해 필요한 작업의 최소 횟수
    if(avail) return answer;
    else return -1;
}