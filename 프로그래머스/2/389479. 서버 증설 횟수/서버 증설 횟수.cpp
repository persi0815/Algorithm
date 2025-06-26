#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
같은 시간대에 게임 이용자 m명 증가 -> 서버 1대 푸가 필요
m명 미만이 사용한다면, 서버 증설이 필요하지 않음. 
한번 증설한 서버는 k 시간 동안 운영. 그 이후 반납
모든 게임 이용자가 게임을 하기 위해 서버를 최소 몇 번 증설해야 하는가?

m명 이상이면 필요한 수만큼 증설 -> k 시간 내에 또 이상이면 증가 x
*/
// 시간대별 게임 이용자 수: players
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    unordered_map<int, int> mm; // {증설 시간, 서버 개수}
    int time = 0; // 현재 시각
    int server_num = 0; // 현재 가지고 있는 서버 개수
    
    for (int p : players) {
        
        // 만료된 서버 제거
        for(auto m: mm){
            if(time - m.first >= k) {
                server_num -= m.second;
                mm.erase(m.first);
            }
        }
        // for (auto it = mm.begin(); it != mm.end(); ) {
        //     if (time - it->first >= k) {
        //         server_num -= it->second;
        //         it = mm.erase(it); // 삭제 후 다음 iterator 반환
        //     } else {
        //         ++it; // 삭제 안 했으면 다음 iterator로 이동
        //     }
        // }

        int required = p / m;

        if (required > server_num) {
            int to_add = required - server_num; // 필요한 추가 서버 수
            answer += to_add;
            server_num += to_add;
            mm[time] = to_add;
            
            cout << "시간: " << time << ", 추가 서버: " << to_add << ", 현재 서버: " << server_num << ", 누적 증설 횟수: " << answer << endl;
        }
        
        time++;
    }
    
    return answer;
}