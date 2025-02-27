#include <iostream>
#include <string>
#include <vector>
#include <sstream> // 문자열 처리
#include <unordered_map>
using namespace std;
// 주고받은 선물 기록으로 다음 달에 누가 선물 받이 받을지 예측하려함

unordered_map<string, int> name_num; // 이름과 번호 매핑
vector<int> gett[50]; // 누구에게 선물 받았는지 나타내는 인접 리스트
vector<int> score(50, 0); // 이름에 대응하는 선물 지수 파악
vector<int> next_m(50, 0);

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int num_friends = friends.size();
    int num_gifts = gifts.size();
    
    // 이름과 번호 매핑
    int num = 0;
    for(const string& name: friends){
        name_num[name] = num++;
    }
    
    // 선물 인접 리스트와 선물 지수 계산
    for (const string& str : gifts) {
        stringstream ss(str);
        string a, b;
        ss >> a >> b; // a -> b 줌
        
        int giver = name_num[a];
        int getter = name_num[b];
            
        gett[getter].push_back(giver);
        score[giver]++; score[getter]--; 
     }
    
    // 두명씩 짝지어가면서 선물 누가 받을지 계산
    for(int i = 0; i < num_friends; i++){
        for(int j = i+1; j < num_friends; j++){
            // 서로 주고 받은 기록 있다면 개수 세기
            int get_i = 0; int get_j = 0;
            for(int k = 0; k < gett[i].size(); k++){
                if(gett[i][k] == j) get_i++;
            }
            for(int k = 0; k < gett[j].size(); k++){
                if(gett[j][k] == i) get_j++;
            }
            
            // 기록에 차이가 없다면 선물 지수가 더 큰 사람이 하나 받기
            if(get_i == get_j){
                if(score[i] > score[j]){
                    next_m[i]++;
                }else if(score[i] < score[j]){
                    next_m[j]++;
                }else{
                    // 선물지수까지 같다면, 주고받지 않음
                }
            }
            // 기록에 차이가 있다면 더 많이 준 사람이 하나 받기
            else if(get_i > get_j){
                next_m[j]++;
            }else{
                next_m[i]++;
            }
            
        }
    }
    
    // 선물 가장 많이 받을 친구가 받을 선물 수 알아내기
    int max_n = 0;
    for(int i = 0; i < num_friends; i++){
        if(max_n < next_m[i]) max_n = next_m[i];
    }
    
    answer = max_n;
    return answer;
}