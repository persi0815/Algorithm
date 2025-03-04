#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
/*
x가 주어졌을 때 x번째 분수를 구하는 프로그램
*/
int main() {
    int x; cin >> x;
    // 1, 2, 3, 4, 5, 6.. 차례로 빼가며 몇 번째 줄인지 파악하기. 
    
    int minu = 1;
    while(x > 0){
        x -= minu; minu++;
    }
    x += (minu-1); 
    
    // minus값이 홀수일때 분모와 분자의 합이 minu+1. 분자값이 x
    if(minu % 2 != 0)
        cout << x << "/" << minu-x;
    else
        cout << minu-x << "/" << x;
}