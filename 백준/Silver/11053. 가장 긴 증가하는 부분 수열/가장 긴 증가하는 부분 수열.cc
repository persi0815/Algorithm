#include <vector>
#include <iostream>
using namespace std;
// 해당 자리에 해당 수까지 만들 수 있는 가장 긴 수열의 길이를 저장

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> len(n, 1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // 이전 인덱스의 arr값보다 크면 해당 인덱스 + 1 저장
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(arr[j] < arr[i])
                len[i] = max(len[i], len[j]+1);
        }
    }
    
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, len[i]);
    }
    
    cout << res;
}