#include <string>
#include <vector>
// 그냥 bfs나 dfs로 하면 막혔던 길을 거슬러 올라가 다시 시도하지 않음. 
// 중복해서 방문하면 양과 늑대가 추가되지 않음. 
// root노드에서 전체적으로 depth가 높아지면서 최대한 많은 양들을 모으면 됨!

using namespace std;
int answer;
vector<vector<int>> adj;
vector<int> candidate; 

void dfs(vector<int>& info, vector<int> candidate, int sheep, int wolf){
    for(int i = 0; i < candidate.size(); i++){    
        int node = candidate[i]; 
        int sheepNum = info[node] == 0 ? sheep+1 : sheep; 
        int wolfNum = info[node] == 1 ? wolf +1 : wolf;
        answer = max(answer, sheepNum);
        
        // 이동이 불가능(늑대 >= 양)이 되면 다른 후보지 선택 
        // -> 전부 불가하면 다음 턴으로 넘어가지만, 후보지군은 줄어들음. 
        if(wolfNum >= sheepNum) continue;
        
        // 이동 가능하면 후보지군 늘리기, 기존에서 자신 뺀 리스트도 더하기 
        vector<int> next_candidate = candidate; 
        next_candidate.erase(next_candidate.begin()+i);
        for(auto& child: adj[node]){
            next_candidate.push_back(child);
        }
            
        // 다음 턴으로 이동
        dfs(info, next_candidate, sheepNum, wolfNum);
        
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    // 전역변수 초기화
    answer = 0; 
    adj.assign(info.size(), vector<int>());
    
    // 인접리스트 만들기 
    for(auto& e: edges){
        int a = e[0]; int b = e[1];
        adj[a].push_back(b); 
    }
    
    // 후보군 중 하나 골라 가기
    candidate.push_back(0);
    dfs(info, {0}, 0, 0);
    
    // 모을 수 있는 양 최대 수
    return answer;
}