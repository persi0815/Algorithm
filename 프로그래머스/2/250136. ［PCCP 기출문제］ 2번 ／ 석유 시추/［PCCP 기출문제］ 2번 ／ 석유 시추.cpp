#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set> 
#include <unordered_map>
#include <queue>
using namespace std;
/*
해당 열에 몇 크기만큼의 석유가 있는지. 겹치면 안됨. 
*/
vector<pair<int, int>> dyx = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
int visit(vector<vector<int>>& land, int i, int j, int num){
    int n = land.size(); // 행 
    int m = land[0].size(); // 열
    
    int size = 1; // 해당 좌료로부터 시작되는 석유 땅의 크기
    queue<pair<int, int>> q; 
    q.push({i, j}); // 시작 좌표
    land[i][j] = num;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second; 
        q.pop(); 
        
        for(int i = 0; i < 4; i++){
            int ny = y + dyx[i].first; 
            int nx = x + dyx[i].second; 
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue; 
            if(land[ny][nx] != 1) continue; 
            land[ny][nx] = num; // 번호 붙이기
            //cout << ny << " " << nx << endl;
            q.push({ny, nx}); 
            size++; 
        }
    }
    return size; 
}

// 석유가 묻힌 땅과 석유 덩어리를 나타내는 배열(0: 빈땅, 1: 석유땅)
int solution(vector<vector<int>> land) {
    int n = land.size(); // 행 
    int m = land[0].size(); // 열
    
    int answer = 0; // 시추관 하나를 설치해 뽑을 수 있는 가장 많은 석유량
    
    // bfs? 로 크기 알아내기 -> 방문 표시 (번호로 2번 부터~)
    int num = 2; 
    // => 결과는 map에 번호와 크기 매핑
    unordered_map<int, int> size; // {땅id, 땅 크기}
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(land[i][j] == 1) {
                size[num] = visit(land, i, j, num);
                //cout << i << " " << j << " " << num << " " << size[num] << endl;
                num++;
            }
        }
    }
    
    // 해당 열에서 지나가는 석유 땅 map, set으로 관리
    unordered_map<int, unordered_set<int>> cross; // {열idx, {지나가는 땅id,,}}
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(land[i][j] != 0) cross[j].insert(land[i][j]);
        }
    }
    
    // 모든 열 돌며 뽑을 수 있는 가장 많은 석유량 갱신
    for(int i = 0; i < m; i++){
        int s = 0; 
        unordered_set<int> c = cross[i]; 
        for(int id: c){
            s += size[id];
        }
        answer = max(answer, s); 
    }
    
    return answer;
}