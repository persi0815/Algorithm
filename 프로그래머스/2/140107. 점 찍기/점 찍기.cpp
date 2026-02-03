#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long K = k; // long long 타입으로 아래 식의 1,000,000^2 핸들링 가능하도록
    long long D = d;

    for(double a = 0; a*K <= D; a++){
        double bkmax = sqrt((D*D) - (a*a*K*K)); // 내부에서는 나눗셈을 제거해 long long 타입으로도 핸들 가능하도록
        answer += (floor(bkmax/K) + 1);  // double 타입의 변수를 나누어 소수점 살리기
    }
    
    return answer;
}