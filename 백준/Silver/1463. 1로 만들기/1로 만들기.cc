#include <iostream>
#include <vector>
using namespace std;
// n부터 연산하면 길이 하나가 아니야 -> 답이 하나로 정해지는 것부터 탐색 
// -> bottom-up으로 1부터 연산의 횟수 계산해나가자. 

int main(){
    int n; cin >> n;
    
    vector<int> arr(n+1, 1000000);
    arr[1] = 0; arr[2] = 1; arr[3] = 1;
    
    for(int i = 4; i <= n; i++){
        if(i % 3 == 0){
            arr[i] = min(arr[i], arr[i/3] + 1);
            
            if(i % 2 == 0){
                arr[i] = min(arr[i], arr[i/2] + 1);
            }
        }
        else if(i % 2 == 0){
            arr[i] = min(arr[i], arr[i/2] + 1);
        }
 
        arr[i] = min(arr[i], arr[i-1] + 1);
    }
    
    cout << arr[n];
}