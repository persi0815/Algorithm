#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
/* 회전초밥
1. 벨트의 임의의 한 위치부터 k개의 접시를 연속해서 먹을 경우 할인된 정액 가격으로 제공한다. 
2. 종류 하나쓰인 쿠폰 발행. 해당 초밥 무료 게공. 벨트 위에 없다면, 새로 만들어 제공

손님이 먹을 수 있는 초밥 가짓수의 최댓값은? 
벨트에서 최대한 안겹치게 구간 고름 -> 쿠폰과 안겹치는 거 

투 포인터로 개수 세는데, 쿠폰과 겹치는게 있는지 없는지 표시
map으로 개수
*/

int n, d, k, c; 
int result = 0;
int main(){
    cin >> n >> d >> k >> c; 
    // 접시 수, 초밥 가짓수, 연속해서 먹는 접시 수, 쿠폰 번호 - 3000
    vector<int> v(n); 
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    unordered_map<int, int> m; // {번호, 개수}
    
    // 미리 넣기
    for(int i = 0; i <= k-1; i++){
        m[v[i]]++;
    }
    result = m.size(); 
    
    // 투포인터 시작
    int left = 0; int right = k-1; 
    while(left < n){
        // 가짓수 파악
        if(m.find(c) == m.end()) 
            result = max(result, (int)m.size()+1); 
        else result = max(result, (int)m.size());
        // cout << "res: " << left << " " << result << endl;
        // for(auto mm:m) 
        //     cout << mm.first << " " << mm.second << endl;
        
        // 새거 넣기
        if(--m[v[left]] == 0) m.erase(v[left]); 
        left++; 
        right = (right+1)%n;
        m[v[right]]++;
        
        
    }
    
    cout << result;
    
}