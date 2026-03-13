#include <string>
#include <vector>

using namespace std;
// f = x보다 크고 x와 비트가 1~2개 다른 수들 중에서 제일 작은 수
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    //  수 돌아가며 첫 0 위치 찾기. 직전 1의 위치도 파악하자. 없으면 건너뜀. 
    // 100,000 * 50
    for(auto n : numbers){
        int one_id = -1;
        int zero_id = -1;
        for(int i = 0; ; i++){
            if((1LL << i) & n){ // 1
                one_id = i; // 가장 큰 1의 자리를 0으로
            }else{ // 0
                zero_id = i; // 첫 0의 자리를 1로
                break;
            }
        }
        n |= (1LL << zero_id); // 그 부분만 1로
        if(one_id != -1) n &= ~(1LL << one_id); // 그 부분만 0으로
        answer.push_back(n);
    }
    
    // numbers의 모든 수들에 대하여 각 수의 f 값을 배열에 차례대로 담아 return
    return answer;
}