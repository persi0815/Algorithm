#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/* 양팔저울
추들의 무게와 확인할 구슬들의 무게가 입력되었을 때, 주어진 추만을 사용하여 구슬의 무게를 확인할 수 있는지 결정하는 프로그램

*/
int t, g;
int dp[40001]; // 0으로 초기화
vector<int> w;
vector<int> gs;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    unordered_set<int> s;
    
    // 입력
    cin >> t; // 추
    for(int i = 0; i < t; i++){
        int tt; cin >> tt;
        w.push_back(tt);
    }
    
    // 추들로 각 구슬의 무게에 대해 확인이 가능하면 Y, 아니면 N
    cin >> g; // 구슬
    for(int i = 0; i < g; i++){
        int gg; cin >> gg;
        gs.push_back(gg);
    }
    

    // 로직 - 추들끼리 더하고 빼고
    dp[0] = true;
    
    // 합 구하기
    for(int j = 0; j < w.size(); j++){ // 30
        for(int i = 40000; i >= 0; i--){ // 40000
            if(i == w[j]) dp[i] = 1;
            
            if(i-w[j] < 0) continue;
            if(dp[i-w[j]] == 1 && !dp[i]) dp[i] = 1; 
        }
    }
    

    // 구한 합들들간의 차 구하기
    for(int i = 0; i < 40000; i++){
        for(int j = i+1; j <= 40000; j++){
            if(dp[i] == 1 && dp[j] == 1 && dp[j-i] == 0) {
                dp[j-i] = 2;
                //cout << j << " " << i << " ";
            }
        }
    }
    
    // 출력
    for(int gss : gs){  
        if(dp[gss] == 0) cout << "N" << " ";
        else if(dp[gss] == 1 || dp[gss] == 2) cout << "Y" << " ";
    }
   
    
}