#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
일정 피로도 -> 던전 탐험
시작 위한 '최소 필요 피로도', 던전 탐험 마쳤을때 소모되는 '소모 피로도' 존재

던전을 최대한 많이 탐험하려고 함. 
현재 피로도 k, 던전별 최소 피로도랑 소모 피로도가 담긴 dungeons
=> 유저가 탐험할 수 있는 최대 던전 수? 
*/ 

int maxCount = 0;

void dfs(vector<vector<int>>& dungeons, int k, vector<bool>& visited, int count) {
    maxCount = max(maxCount, count);

    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            dfs(dungeons, k - dungeons[i][1], visited, count + 1);
            visited[i] = false; // backtrack
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<bool> visited(dungeons.size(), false);    
    dfs(dungeons, k, visited, 0); 
    answer = maxCount;
    
    return answer;
}