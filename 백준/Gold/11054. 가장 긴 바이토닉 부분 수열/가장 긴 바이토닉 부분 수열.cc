#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/* 
증가 -> 감소 : 바이토닉 수열
수열 a가 주어졌을 때, 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이 찾기.
*/

int n;
vector<int> a;


int main(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<int> increase(n, 1); 
    // 증가
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(a[i] > a[j]){
                increase[i] = max(increase[j] + 1, increase[i]);
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << increase[i] << " ";
    // }
    // cout << endl;


    vector<int> decrease(n, 1);
    // 감소
    for(int i = n-2; i >= 0; i--){
        for(int j = i+1; j <= n-1; j++){
            if(a[i] > a[j]){
                decrease[i] = max(decrease[j] + 1, decrease[i]);
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << decrease[i] << " ";
    // }
    // cout << endl;
    
    int res = 0;
    for(int i = 0; i < n; i++){
        if(increase[i] + decrease[i] - 1 > res)
            res = increase[i] + decrease[i] - 1;
    }
    
    cout << res;
    
    
    
}