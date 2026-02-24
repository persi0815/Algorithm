#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    sort(stations.begin(), stations.end()); 
    
    // 닿지 않는 곳 {시작, 끝}을 넣기
    vector<pair<int, int>> range; 
    int last = 1; // 처음으로 닿지 않은 곳
    for(auto & s : stations){
        // 처음으로 닿지 않은 곳보다 시작하는 곳이 더 뒤라면 사이의 남는 곳 넣기
        int start = s-w;
        int end = s+w;
        if(last < start){
            range.push_back({last, start-1}); 
        }
        last = end+1;
        
    }
    // 마지막에 남는 곳이 있다면 넣기
    if(last <= n) range.push_back({last, n}); 

    // 연속된 닿지 않는 곳 구간 길이로 판별
    for(auto& r: range){
        int start = r.first; 
        int end = r.second; 
        int length = end-start+1;
        if(length <= (w*2+1)) answer++; 
        else{
            if(length % (w*2+1) == 0) answer += length / (w*2+1);
            else answer += (length / (w*2+1)) + 1;
        }
        // cout << start << " " << end << " " << answer << endl;
    }
    return answer;
}