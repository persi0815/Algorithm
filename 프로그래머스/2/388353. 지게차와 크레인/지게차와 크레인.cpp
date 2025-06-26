#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
/*
알파벳 대문자로 종류 구분. 세로 n, 가로 m
지게차(한번) - 접근이 가능한 해당 종류의 컨테이너 전부 꺼냄. 4면 중 적어도 1면이 외부외 연결
크레인(두번) - 외부와 연결되지 않아도 전부 꺼낼 수 있음. 

모든 요청을 순서대로 완료한 후, 남은 컨테이너 수 리턴
두번 반복 -> 무조건 다 꺼내기 / 한번 -> .와 맞닿아있는거 전부
한단계씩 앞으로 가는게 중요!!
*/

vector<pair<int,int>> dyx = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
int n, m;

void bfs(string order, vector<vector<string>>& arr, vector<vector<bool>>& visited){
    queue<pair<int, int>> q; 
    q.push({0, 0});
    visited[0][0] = true;
    
    while(!q.empty()){
        auto t = q.front(); q.pop(); 
        int y = t.first; int x = t.second;
        
        for(int i = 0; i < 4; i++){
            int ny = y + dyx[i].first; 
            int nx = x + dyx[i].second; 
            if(nx < 0 || nx >= m+2 || ny < 0 || ny >= n+2) continue; 
            if(visited[ny][nx]) continue; 
            
            if(arr[ny][nx] == order){
                arr[ny][nx] = "."; 
                visited[ny][nx] = true; // 방문 처리만, 확장은 X
            }
            else if(arr[ny][nx] == ".") {
                q.push({ny, nx}); 
                visited[ny][nx] = true;
            }
        }
    }
}


void all_erase(char order, vector<vector<string>>& arr){
    cout << "all_erase" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] == string(1, order)) arr[i][j] = ".";
        }
    }
}

int count_left(vector<vector<string>> &arr){
    cout << "count_left"<< endl;
    int num = 0;
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(arr[i][j] != ".") num++;
        }
    }
    return num;
}

// 처음 물류창고에 놓인 컨테이너의 정보 -> storage
// 출고할 컨테이너 -> requests
int solution(vector<string> storage, vector<string> requests) {
    int answer = 0; // 남은 컨테이너 수
    
    // 위치 재배열
    n = storage.size(); m = storage[0].size(); 
    vector<vector<string>> arr(n+2, vector<string>(m+2, ".")); 
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            arr[i][j] = storage[i-1][j-1];
        }
    }
    
    // 요청마다
    for(int i = 0; i < requests.size(); i++){ 
        string order = requests[i]; 
        
        // 지게차
        if(order.size() == 1){
            vector<vector<bool>> visited(n+2, vector<bool>(m+2, false)); 
            bfs(order, arr, visited);
            
        } 
        // 크레인
        else if(order.size() == 2){
            all_erase(order[0], arr);
        }
        
    }
    
    // 남은 컨테이너 개수 세기
    answer = count_left(arr);
    
    return answer;
}