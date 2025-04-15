#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
바로 앞, 뒷 번호 학생에게만 빌려줄 수 있음. 
체육복을 절적히 빌려 최대한 많은 학생이 체육 수업을 들어야 함.
여벌 체육복을 가져온 학생이 도난 당했으면 자기가 입어야 하니까 못 빌려줌!!!
=> 그리디. 맨 앞부터 받을 수 있는 학생에게 받기. 
*/

// 학생수 n, 도난당한 학생들 번호 lost, 여분 체육복 가진 학생 reserve
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end()); 
    sort(reserve.begin(), reserve.end());
    int get = 0; // 받은 학생 명수
    
    // lost에 있는데, reserve에도 있음 -> 못 빌려주니까 reserve 재구성
    vector<int> n_reserve;
    vector<int> n_lost;
    int idx = 0;
    for(int r: reserve){
         if(find(lost.begin(), lost.end(), r) == lost.end()){
             n_reserve.push_back(r);
         }   
    }
    idx = 0;
    for(int l: lost){
         if(find(reserve.begin(), reserve.end(), l) == reserve.end()){
             n_lost.push_back(l);
         }   
    }
    
    // 체육복 받기
    int idxx = 0;
    for(int l : n_lost){ // 학생 번호
        while(idxx < n_reserve.size() && n_reserve[idxx] < l-1) { // 줄 수 있는 친구가 너무 작아
            idxx++; // 줄 수 있을때까지 이동
        }
        if(idxx >= n_reserve.size()) break;
        // 빌려줄 수 있음
        if(l == n_reserve[idxx] - 1 
           || l == n_reserve[idxx] 
           || l == n_reserve[idxx] + 1){
            get++; // 수령
            idxx++; 
        }
    }
    

    answer = n - (n_lost.size() - get);
    return answer;
}