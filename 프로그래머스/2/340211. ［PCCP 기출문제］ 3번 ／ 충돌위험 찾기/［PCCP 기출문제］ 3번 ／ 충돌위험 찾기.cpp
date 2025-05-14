#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
/*
로봇 이용한 자동 운송 시스템. 
1~n까지의 서로 다른 번호 가진 n개의 포인트 -> 좌표 접근시 +1해주자
로봇마다 정해진 운송 경로 - m개의 포인트로 구성되고, 할당된 포인트 순서대로 방문
-> 각각의 로봇의 이동 경로 판단. 몇 초에 어딘지. 점점 갱신 -> 겹치면 횟수 += 1
사용되는 로봇 x대, 모든 로봇 0초에 출발. 
다음 포인트로 이동 시 항상 최단 경로로 이동. 최단 경로가 여러 가지일 경우, 행->열
마지막 포인트에 도착하면, 운송 마치고, 물류 센터 벗어남. 

로봇이 충돌할 가능성이 있는 상황이 총 몇번 일어나는지 판단. 상황 개수를 다 더하기
*/

// 운송 포인트 n개의 좌표, 로봇 x대의 운송 경로
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0; // 위험한 상황의 횟수
    int n = points.size(); // 운송 포인트
    int x = routes.size();  // 로봇 개수
    int route_size = routes[0].size(); 
    
    vector<pair<int, int>> curr(x); // 각 로봇의 현재 위치
    vector<int> dest_r_idx(x); // 각 로봇이 현재 어떤 route(idx)로 가고 있는지 
    int idx = 0;
    for(auto route: routes){
        curr[idx].first = points[route[0]-1][0]; // y
        curr[idx].second = points[route[0]-1][1]; // x
        dest_r_idx[idx] = 1; // 모든 로봇의 목적지는 두번째 route임
        idx++;
    }    
    
    // 0초에서의 충돌
    unordered_map<string, int> zero; 
    for(auto cur: curr){
        zero[to_string(cur.first)+","+to_string(cur.second)]++;
    }
    int collu = 0; 
    for(auto m: zero){
        if(m.second > 1) collu++;
    }
    answer += collu;
    
    int fin = 0;
    while(fin < x){ // 모든 로봇이 끝날때까지 진행 - 한 턴
        unordered_map<string, int> yx; // 겹치는거 있는지 확인 
        int active = 0;
        
        // 로봇이 경로 다다르면 현재 어디로 가고 있는지 갱신
        for(int i = 0; i < x; i++){
            if(dest_r_idx[i] == -1) continue;
            active++;
            
            int cur_y = curr[i].first;
            int cur_x = curr[i].second; 
            int p_idx = routes[i][dest_r_idx[i]] - 1;
            int des_y = points[p_idx][0];
            int des_x = points[p_idx][1];
            
            // 이동시키기
            if (cur_y != des_y)
                curr[i].first += (des_y > cur_y ? 1 : -1);
            else if (cur_x != des_x)
                curr[i].second += (des_x > cur_x ? 1 : -1);
            
            // 이동 결과 set에 넣기
            yx[to_string(curr[i].first)+","+to_string(curr[i].second)]++;
            
            // 만약 같아졌다면? 즉, 모든 경로 다 돌았다면? 해당 로봇은 끝
            if(curr[i].first == des_y && curr[i].second == des_x){
                dest_r_idx[i]++;
                if(dest_r_idx[i] == route_size) {
                    dest_r_idx[i] = -1; fin++;
                }
            }
            
        } // 로봇 전부 이동
        
        
        // 로봇 전부 다 이동한 후, 충돌 횟수 갱신
        int collusion = 0; 
        for(auto m: yx){
            if(m.second > 1) collusion++;
        }
        answer += collusion; // 충돌난 좌표의 개수를 구해야
    }
    
    return answer;
}