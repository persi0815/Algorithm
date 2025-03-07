#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 0 만들기
오름차순으로 쓴 수열 에서 +, -, " "을 숫자 사이에 삽입하자
수식의 값을 계산하고, 그 결과가 0이 될 수 있는지 살피자.
각 테스트 케이스에 대해 아스키 순서에 따라 결과가 0이 되는 모든 수식 출력하자. 
*/

int t; 
char sig[3] = {' ', '+', '-'};
int res = 0; 

void print(vector<char> &arr){
    for(char c: arr) cout << c;
    cout << endl;
}

void calcul(char signal, int now){
    if(signal == '+') res += now;
    else if(signal == '-') res -= now;
}

void make(int n, int num, vector<char> &arr){
    
    if(num == n){ // 마지막 수의 경우
        // 숫자 넣고
        arr.push_back(num+'0');
        
        // arr에 따라 계산
        char signal = '+'; int now = arr[0]-'0';
        
        for(int i = 1; i < arr.size(); i+=2){ // arr[i*2-1], arr[i*2]
            if(arr[i] == ' ') 
                now = now*10 + arr[i+1]-'0';
            else {
                calcul(signal, now); // 현재까지의 연산 수행
                signal = arr[i];     // 새로운 연산자 저장
                now = arr[i + 1] - '0'; // 새로운 숫자 저장
            }
        }
        calcul(signal, now);
        
        if(res == 0) print(arr);
        res = 0; arr.pop_back();
        return ;
    }

    else{
        // 숫자 넣고, " ", +, - 중 하나 넣고 계산 결과 저장해두고. 
        // n까지 왔을때 결과가 0이면 출력하자. 
        for(int i = 0; i < 3; i++){
            // 숫자 넣고 부호 넣기
            arr.push_back(num+'0'); arr.push_back(sig[i]);
            make(n, num+1, arr);
            arr.pop_back(); arr.pop_back();
        }    
    }
        
}

int main(){
    cin >> t;
    while(t--){
        int n; cin >> n;
        res = 0;
        vector<char>arr;
        make(n, 1, arr); // 1일때부터 계산 요청
        cout << endl;
    }
}