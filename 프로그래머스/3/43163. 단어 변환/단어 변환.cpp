#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
begin -> target
words에 있는 단어들을 거쳐서면 변환할 수 있다.
*/
int res = 51; 

void dfs(vector<string>& words, vector<bool>& visited, string now, int cnt, string target){
    if(now == target){
        res = min(res, cnt); 
        return;
    }
    
    for(int i = 0; i < words.size(); i++){
        if(!visited[i]){
            // 한개만 다른지
            string str = words[i];
            int n = 0;
            for(int j = 0; j < str.size(); j++){
                if(str[j] != now[j]) n++;
                if(n > 1) continue;
            }
            if(n == 1) {
                visited[i] = true;
                //cout << str << " ";
                dfs(words, visited, str, cnt+1, target);
                visited[i] = false;
            }
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0; // 몇번을 거쳐야 변환할 수 있는가? 
    
    // 지금 갈 수 있는거 뽑기
    vector<bool> visited(words.size(), false); 
    dfs(words, visited, begin, 0, target);
    
    if(res < 51) answer = res;
    
    return answer;
}