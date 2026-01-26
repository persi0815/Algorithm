#include <string>
#include <vector>
#include <iostream>
#define MOD 1000000007
using namespace std;

vector<long long> prefix_sum(2501, 0);
vector<long long> result(2501, 0);

int solution(int n) {
    
    if(n%2 != 0) return 0;
    
    result[0] = 1; result[1] = 3;
    prefix_sum[0] = 1; prefix_sum[1] = 4;
    
    for(int i = 2; i <= n/2; i++){
        result[i] = ((result[i-1] * result[1]) + (2 * (prefix_sum[i-2]))) % MOD;
        // cout << i*2 << " " << result[i] << endl;
        prefix_sum[i] = (prefix_sum[i-1] + result[i])  % MOD;
    }
    
    
    return result[n/2];
}