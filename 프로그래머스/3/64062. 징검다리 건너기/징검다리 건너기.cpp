#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    // 모든 조약돌은 전체적으로 n을 뺐을때 0이하가 k번 연속으로 발생하는지 확인
    int end = *max_element(stones.begin(), stones.end()); 
    int start = 0;
    while(start <= end){ // 10^3
        int mid = (start+end)/2; 
        int jump = 0;
        bool avail = true;
        for(int i = 0; i < stones.size(); i++){ // 200,000
            if(stones[i] - mid < 0){
                jump++;
                if(jump >= k) {
                    avail = false; break;
                }
            }else{
                jump = 0;
            }
        }
        if(!avail) {
            end = mid-1;
        }else{
            start = mid+1;
            answer = mid;
        }
    }
    
    //  최대 몇 명까지 징검다리를 건널 수 있는지 return
    return answer ;
}