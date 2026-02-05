#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    // 시작부터 끝까지 차례대로 구하기
    for(long long i = left; i <= right; i++){
        if(i - (i/n) <= (i/n)*n) answer.push_back(i/n+1);
        else answer.push_back(i % n + 1);
        
        
    }
    return answer;
}