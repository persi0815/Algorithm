#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    
    // a정렬
    sort(a.begin(), a.end());
    
    // b정렬
    sort(b.begin(), b.end());

    // a 맨 앞부터 b가 이길 수 있는거 싹 이기기 - 가장 작은 수로 그보다 조금 더 작은 수 이기기
    int id = 0;
    for(auto& bb : b){
        if(bb > a[id]){
            answer++;
            id++;
        }
        if(id == a.size()) break;
    }
    
    // 최종 승점을 가장 높이는 방법으로 얻을 수 있는 승점
    return answer;
}