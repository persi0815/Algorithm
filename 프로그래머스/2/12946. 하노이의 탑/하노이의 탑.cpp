#include <string>
#include <vector>

using namespace std;

void hanoi(vector<vector<int>>& answer, int n, int from, int to, int sub){
    if(n==1){
        answer.push_back({from, to}); 
        return;
    }
    // 맨 밑 빼고 전부 2번째로 옮기기
    hanoi(answer, n-1, from, sub, to); // 1 -> 2
    
    // 맨 밑 3번째로 옮기기
    answer.push_back({from, to}); // 1 -> 3
    
    // 2번째 전부 3번째로 옮기기
    hanoi(answer, n-1, sub, to, from); // 2 -> 3
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(answer, n, 1, 3, 2);
    
    return answer;
}