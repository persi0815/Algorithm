#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, int s) { // 집합의 원소의 개수 n과 모든 원소들의 합 s
    vector<int> answer = {-1}; // 존재하지 않을 경우
    
    // s를 n으로 나누고, 나머지가 있으면 그만큼 늘려서 계산
    int r = s/n; 
    if(r > 0 && s%n == 0){
        answer.assign(n, r);
    }else if(r > 0){
        answer.assign(n, r);
        fill(answer.end()-s%n, answer.end(), r+1);
    }
    
    return answer;
}