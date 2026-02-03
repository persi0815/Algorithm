#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(long long begin, long long end) {
    // 시작부터 끝까지 하나씩 돌며 가장 큰 약수 구하고 배열에 넣기
    vector<int> answer;
    
    for(long long i = begin; i <= end; i++){ // 5000
        // 1의 경우에는 1 넣기
        if (i == 1) {
            answer.push_back(0);
            continue;
        }
        
        long long max_divisor = 1; // 기본값은 1 (소수일 경우)
        // 2부터 나눠지는거 하나 찾으면 그걸로 나누면 됨!
        for(long long j = 2; j * j <= i; j++){ // 2부터 
            if(i % j == 0) {
                long long div = i/j;
                
                if(div > 10000000) max_divisor = j; // 더 작은 결과 찾기
                else {
                    max_divisor = div;
                    break;
                }
            }
        }
        // 약수가 자신과 1이라면 1 들어감
        answer.push_back((int)max_divisor);

    }
    return answer;
}