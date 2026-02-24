#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> work; // max heap
    for(auto& w: works){
        work.push(w);
    }
    
    while(n--){ // 1,000,000 * 28
        int t = work.top(); // 1
        if(t <= 0) break;
        work.pop(); // log2(20,000) = 14
        work.push(t-1); // log2(20,000) = 14
    }
    
    for(int i = 0; i < works.size(); i++){ // 20,000 * 14
        answer += work.top()*work.top();
        work.pop();
    }
    
    return answer;
}