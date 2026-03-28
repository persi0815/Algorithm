#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    
    // 해당칸을 밟았을때 얻을 수 있는 최고 점수
    vector<vector<int>> score = land; 
    
        int y = 0;
        while(y < land.size()-1){ // y
            
            for(int x = 0; x < 4; x++){ // x
                for(int j = 0; j < 4; j++){ // 1~4열
                    if(j != x) score[y+1][j] = max(score[y+1][j], score[y][x] + land[y+1][j]); 
                }
            }
            
            y++;
        } 
      
    
    answer = *max_element(score[land.size()-1].begin(), score[land.size()-1].end());

    return answer; // 최종 최고 점수
}