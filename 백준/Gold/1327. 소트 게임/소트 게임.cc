#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;
/*
1~N까지 정수로 이루어진 순열 이용
K 주어짐 -> 어떤수 뒤집으면, 그 수부터 오른쪽으로 K개의 수 뒤집어야 함. 
뒤집기를 통해 순열을 오름차순으로 만들려고 함. 
수를 최소 몇개 선택해야 할까? 
*/

int n, k;
// unordered_set<string> visited;
unordered_set<int> visited;

bool check(string str){
    for(int i = 1; i < n; i++){
        if (str[i - 1]-'0' > str[i]-'0') return false;  
    }
    return true;
}


int bfs(string str, int cnt){
    queue<pair<string, int>> q;
    q.push({str, cnt});
    visited.insert(stoi(str));
    
    while(!q.empty()){
        string str = q.front().first;
        int cnt = q.front().second;
        q.pop();
    
        if(check(str)) {
            return cnt;
        }
        
        for(int st = 0; st <= n-k; st++){ // 점차 뒤로
            string n_str = str;
            //for(int i = 0; i < k/2; i++){ // 뒤집기 전과
            //    char c = n_str[st + i];
            //    n_str[st +i] = n_str[st +k-i-1]; 
            //    n_str[st +k-i-1] = c;
            //}
            reverse(n_str.begin() + st, n_str.begin() + st + k);
            
            if(visited.find(stoi(n_str)) == visited.end()){
                visited.insert(stoi(n_str));
                q.push({n_str, cnt + 1});
            } 
        }
        
        
    }
    return -1;
    
}

int main() {
    cin >> n >> k;
    
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        arr.push_back(num);
    }
    
    string str = "";
    for(int num: arr){
        str += to_string(num);  
    }
    
    int result = bfs(str, 0);
    cout << result << endl;

    
    return 0;
}
