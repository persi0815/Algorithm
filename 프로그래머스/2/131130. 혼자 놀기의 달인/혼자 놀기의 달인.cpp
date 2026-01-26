#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<bool> visited(cards.size(), false);
    vector<int> group[cards.size()];
    int group_num = 0;
    
    // 시작점 지정 (100)
    for(int i = 1; i <= cards.size(); i++){
        if(visited[i]) continue;
        
        int id = i; visited[id] = true; group[group_num].push_back(id);
        while(true){ // 한 사이클 만들기
            int num = cards[id-1];
            // cout << num << endl;
            if(!visited[num]) { // 방문한적 없으면
                visited[num] = true;  // 방문해서
                group[group_num].push_back(num); id = num; // 삽입
            }
            else {
                group_num++; 
                // cout << "next" << endl;
                break;
            }
        }
    }
    
    vector<int> size;
    for(auto & g: group) {
        size.push_back(g.size()); 
        // cout << "size: " << g.size() << endl;
    }
    sort(size.begin(), size.end(), greater<int>());
       
    return size[0] * size[1];
}