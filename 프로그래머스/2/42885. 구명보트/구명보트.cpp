#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
한 번에 2명씩 밖에 못탐. 무게제한도 있음. 
무게제한 때문에 1명씩만 탈 수도 있는 것. 
구명보트 최대한 적게 사용하여 모든 사람 구출하려고 함. 
=> 모든 사람 구출 위해 필요한 구명보트의 개수의 최솟값? 
*/

// 사람들 몸무게 담은 배열. 구명보트의 무게제한. 
int solution(vector<int> people, int limit) {
    int answer = 0; // 구명 보트의 개수
    
    // 오름차순 정렬
    sort(people.begin(), people.end()); 
    
    // 투 포인터로 가벼운 사람과 같이 탈 수 있는 무거운 사람 짝짓기
    int right = 0; int left = people.size() -1;
    while(right <= left){
        if(right == left){ // 마지막에 한명 남으면 혼자 태우기
            answer++; 
            break;
        }
        else if(people[right] + people[left] > limit){
            answer++; 
            left--;
        }else{
            answer++; 
            right++; left--;
        }
    }
    
    return answer; 
}