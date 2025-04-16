#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
직접 혹은 간접으로 연결되어 있다면 같은 네트워크 상에 있다고 할 수 있음
=> 네트워크의 개수 반환
*/

void dfs(int n, vector<bool>& visited, vector<int> arr[n]){
    for(int i = 0; i < arr[n].size(); i++){
        if(!visited[arr[n][i]]){
            visited[arr[n][i]] = true;
            dfs(arr[n][i], visited, arr);
        }
    }
}

// 컴퓨터의 개수, 연결에 대한 정보가 담긴 배열
int solution(int n, vector<vector<int>> computers) {
    int answer = 0; // 네트워크 수
    vector<bool> visited(n, false); // 방문 표시 
    
    vector<int> arr[n]; // 인접 리스트
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(computers[i][j] == 1){
                arr[i].push_back(j); 
                arr[j].push_back(i); 
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(!visited[i]) {
            dfs(i, visited, arr);
            answer++;
        }
    }

    return answer;
}