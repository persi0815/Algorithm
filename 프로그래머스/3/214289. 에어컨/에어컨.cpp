#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;
/*
승객 탑승 중일때 실내욘도(T1~T2) 유지함. 
에어컨 - 희망 온도 설정. 켜져있는 동안 원하는 희망온도 값으로 변경 가능
1분뒤 실내 온도가 희망온도와 같아지는 방향으로 +1 혹은 -1
전원 끄면 실내온도가 실외온도와 같아지는 방향으로 매분 +1 -1

소비전력은 실내 온도에 따라 달라짐. 
희망과 실내가 다르면 매분 A만큼 소비, 같다면 B만큼 소비. 꺼져있다면 소비X
차내에 승객이 탑승 중일 때 실내온도를 T1~T2로 유지하면서 에어컨의 소비전력을 최소화
*/

int dp[1001][51][2][3] = {-1}; // [time][temp+OFFSET][on][hope+1]

// 파라미터에는 이전 시간의 에어컨으로 바뀐 결과가 들어감!
int aircon(int time, int temp, bool on, int hope, int t1, int t2, int a, int b, int out, vector<int>& onboard){
    
    // 마지막까지 갔는데 계속 온도가 맞았어
    if(time == onboard.size()) return 0;
    
    if (temp < -10 || temp > 40) return INT_MAX;
            
    // 승객 탔는데, 온도가 안맞아
    if (onboard[time] == 1 && (temp < t1 || temp > t2)) return INT_MAX; 

    int& ret = dp[time][temp+10][on][hope+1];
    if (ret != -1) return ret;
    
    // 디버깅
    if(out == 11 && b == 1 && time == 1)
        cout << time << " " << onboard[time] << " " << temp << " " << hope << endl;
    
    // 이전 활동으로 결과 갱신
    int m_cost = INT_MAX;
    int n_temp; int n_cost;
        
    if(on){ // 켜져있어
        n_temp = temp + hope; // 온도 변화
        
        n_cost = (hope == 0) ? b : a;
    }
    else{ // 안 켜져있어
        if(temp < out) n_temp = temp + 1;
        else if(temp > out) n_temp = temp - 1;
        else n_temp = temp;
        
        n_cost = 0;
    }
    
    for(int i = 0; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int next = aircon(time + 1, n_temp, i, j, t1, t2, a, b, out, onboard);
            if (next != INT_MAX) {
                m_cost = min(m_cost, n_cost + next);
            }
        }
    }

    return dp[time][temp+10][on][hope+1] = m_cost;
    
}


int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = INT_MAX;
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i <=1; i++){
        for(int j = -1; j <= 1; j++){
            answer = min(answer, 
                         aircon(0, temperature, i, j, t1, t2, a, b, temperature, onboard));
        }
    }
    
    return answer; // 최소 소비 전력
}