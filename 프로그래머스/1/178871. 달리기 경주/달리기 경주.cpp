#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    // players: 현재 등수 순서대로 담김. calling: 해설진이 부른 이름
    vector<string> answer;
    
    int num_players = players.size();
    int num_callings = callings.size();
    
    // 이름과 등수 매핑되어 있는 map 
    // -> 보다 쉽게 이름으로 등수 배열 위치 알 수 있지 않을까? 
    unordered_map<string, int> score;
    for(int i = 0; i < num_players; i++){
        score[players[i]] = i;
    }
    
    // 이름 부를 때마다 해당 사람이랑 그 앞사람이랑 순서 바꾸기
    for(int i = 0; i < num_callings; i++){
        int idx = score[callings[i]];
        // 배열 갱신
        string temp; temp = callings[i]; 
        players[idx] = players[idx-1]; 
        players[idx-1] = temp; 
        // map 갱신
        score[callings[i]] = idx -1; 
        score[players[idx]] = idx;
    }
    
    answer = players;
    return answer; // 경주 끝났을 때 선수들의 이름
}