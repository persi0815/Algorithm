#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
폭격 미사일 요격. 미사일을 최소 사용하여 모든 폭격 미사일 요격하려함. 
a 마사일은 x축에 평행한 직선 형태의 모양. 실수x 좌표에서도 발사 가능
b는 y축에 수평인 마사일 발사. 해당 x좌표에 걸쳐있는 모든 미사일 관통 가능. 
*/

// 폭격 미사일의 x 좌표 목록
int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    vector<pair<int, int>> spot; 
    
    for(auto t: targets){
        spot.push_back({t[1], t[0]}); // 끝 점 기준 오름차순 
    }
    spot.push_back({100000001, 100000001});
    sort(spot.begin(), spot.end()); 
    
    int end = -1;
    for(auto s: spot){
        if(end == -1) end = s.first;
        else{
            if(s.second >= end){
                end = s.first; answer++;
            }
        }
    }
    
    return answer;
}