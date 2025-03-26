#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
두 묶음씩 골라 합쳐나가는데, 고르는 순서에 따라 비교 횟수가 달라짐. 
-> 작은 것들이 더 많이 더해져야 함. 
n개의 숫자 카드 묶음의 각각의 크기가 주어질 때, 최소한 몇 번의 비교가 필요한가? 
우선순위 큐에 넣고 오름차순으로 정렬하고, 
*/
int n; 
int res = 0;
priority_queue<int, vector<int>, greater<int>> pq; // min_heap

int main(){
    cin >> n; // 100,000
    for(int i = 0; i < n; i++){
        int m; cin >> m; pq.push(m);
    }
    
    while(!pq.empty() && pq.size()>=2){ // nlogn -> 100,000,000
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        
        pq.push(a+b); res += a+b;
    }
    cout << res;
    
}