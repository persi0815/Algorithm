#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    // 맨 양옆 가능
    int answer = 2;
    
    // 해당 칸에서 양옆으로 가장 작은 수 구하기
    vector<pair<int, int>> val(a.size(), pair<int, int>()); 
    int minn = INT_MAX;
    for(int i = 0; i < a.size(); i++){
        val[i].first = minn;
        minn = min(minn, a[i]);
    }
    minn = INT_MAX;
    for(int i = a.size()-1; i >= 0; i--){
        val[i].second = minn;
        minn = min(minn, a[i]);
    }
    
    // 양옆으로 가장 작은 수 찾고, 둘 보다 하나라도 작으면 가능!
    for(int i = 1; i < a.size()-1; i++){
        if(val[i].first > a[i] || val[i].second > a[i]) {
            answer++;
        }
    }
    
    // 최후까지 남기는 것이 가능한 풍선들의 개수
    return answer;
}