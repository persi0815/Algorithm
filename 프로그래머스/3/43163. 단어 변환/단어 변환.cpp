#include <string>
#include <vector>
#include <queue>
using namespace std;

bool canChange(string a, string b) {
    int diff = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) diff++;
        if(diff > 1) return false;
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> q; // (현재 단어, 변환 횟수)
    vector<bool> visited(words.size(), false);

    q.push({begin, 0});
    
    while(!q.empty()){
        auto [now, cnt] = q.front();
        q.pop();
        
        if(now == target) {
            answer = cnt;
            break;
        }
        
        for(int i = 0; i < words.size(); i++){
            if(!visited[i] && canChange(now, words[i])) {
                visited[i] = true;
                q.push({words[i], cnt + 1});
            }
        }
    }
    
    return answer;
}
