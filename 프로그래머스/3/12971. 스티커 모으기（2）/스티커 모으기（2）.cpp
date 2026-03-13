#include <iostream>
#include <vector>
#include <iostream>
using namespace std;
// greedy 불가 -> dp 고려
int solution(vector<int> sticker)
{
    int answer = sticker.size() > 1 ? 
        max(sticker[0], sticker[1]) : sticker[0];

    // 첫번째 값 사용o -> 마지막 값 사용x
    vector<int> v1 = sticker; 
    if(sticker.size() >= 3) v1[2] = v1[2] + v1[0];
    for(int i = 3; i < v1.size()-1; i++){ // 100,000
        v1[i] = max(v1[i-1], v1[i] + max(v1[i-2], v1[i-3]));
    }
    answer = max(answer, v1[sticker.size()-2]); 
    
    // 첫번째 값 사용x -> 마지막 값 사용o
    vector<int> v2 = sticker; 
    if(sticker.size() >= 4) v2[3] = v2[3] + v2[1];
    for(int i = 4; i < v2.size(); i++){ // 100,000
        v2[i] = max(v2[i-1], v2[i] + max(v2[i-2], v2[i-3]));
    }
    answer = max(answer, v2[sticker.size()-1]); 
    

    // 스티커를 뜯어내어 얻을 수 있는 숫자의 합의 최댓값을 return 
    return answer;
}