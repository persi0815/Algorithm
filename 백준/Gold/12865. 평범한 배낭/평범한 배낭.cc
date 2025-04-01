#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/* 평범한 배낭
n개의 물건이 무게 w, 가치 v를 가짐
k만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다. 
배낭에 넣을 수 있는 물건 가치의 최댓값?
무게가 작고, 가치가 큰 걸 골라야 함. 
물건 중복되면 안됨 -> 물건을 밖 for문으로
아 내가 지나쳐왔던거 또 지나칠 수가 있네.. 거꾸로 가야겠다. 
*/
// 특정 무게로 최대 얼마의 가치를 얻을 수 있는지

int n, k;
int dp[200001]; //dp[무게] = 가치의 최댓값
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> n >> k; // 물품 수, 버틸 수 있는 무게
    
    for(int i = 0; i < n; i++){ // 100
        int w, v; cin >> w >> v; // 무게, 가치
        
        for(int j = k; j > w; j--){ // 100,000
            if(dp[j-w] == 0) continue;
            dp[j] = max(dp[j], dp[j-w] + v);
        }
        if(dp[w] < v) dp[w] = v;
    }
    cout << *max_element(dp, dp+k+1);
}
