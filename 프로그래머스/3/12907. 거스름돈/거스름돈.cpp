#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> dp(n+1, 0); 
    dp[0] = 1; 
    
    sort(money.begin(), money.end()); // 오름차순
    for(int i = 0; i < money.size(); i++){ // 100
        int m = money[i];
        for(int j = m; j <= n; j++){ // 100,000
            dp[j] += (dp[j-m]); 
        }
    }
    
    return answer = dp[n]; // n 원을 거슬러 줄 방법의 수
}