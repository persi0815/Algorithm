
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
/*
a -> 5000, b -> 1000
남은 학기의 n일 동안 매일 학식의 두 메뉴 중 하나 골라서 먹어야 함. 
얼마나 맛있을지 수치 매겨 둠. 
n일간 x원 이하 사용해야 함. 
메뉴 골라서 고른 메뉴의 맛의 합을 최대화 하자!

해당 가격으로 a 몇개까지 가능한지 계산
그리디: 가장 비싼거부터 고르는데, a 고르면 가능 수 --, 해당 일자 불가능하게? -> 문제 있는데.. 
dp: 조합 구하려면 시간복잡도 넘어가..
그리디: 일단 천원짜리로 계산하고, 가장 가치 차(a-b)가 큰것 선택해가며 진행!
*/

int main(){
    int n, x; cin >> n >> x;
    
    priority_queue<int> pq; // map_heap
    int tot_val = 0;
    
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        tot_val += b;
        pq.push(a-b);
    }
    x -= (1000*n);
    
    while(x>=4000){
        int more = pq.top();
        if(more < 0) break;
        //cout << more << endl;
        tot_val += more; 
        x-= 4000;
        pq.pop();
    }
    
    cout << tot_val;
}