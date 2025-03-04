#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
/*
m이상 n 이하의 소수 모두 출력!
*/
int main() {
    long long m, n; cin >> m >>  n;
    bool arr[1000001];
    fill(arr, arr + 1000001, true);
    arr[0] = arr[1] = false;
    
    for(int i = 2; i <= sqrt(n); i++){
        for(long long j = i*i; j <= n; j += i){
            if(arr[j] == true) arr[j] = false;
        }
    }
    
    for(int i = m; i <= n; i++){
        if(arr[i]) cout << i << endl;
    }
    
}
