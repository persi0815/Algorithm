#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
/* 후보 추천하기
학생회장 후보는 일정 기간 동안 전체 학생의 추천에 의하여 정해진 수만큼 선정
사진틀을 후보의 수만큼 만듦
어떤 학생 추천 -> 사진틀에 게시
비어있는 사진틀이 없는 경우, 현재까지 추천 받은 횟수가 가장 적은 학생 사진 삭제(두 명 이상이라면 오래된 거 삭제) -> 그 자리에 새롭게 추천받은 학생의 사진 게시
게시된 학생이 다른 학생의 추천 받는 경우 추천받은 횟수만 증가시킴
게시된 사진이 삭제된 경우에는 해당 학생의 추천수는 0으로 바뀜

사진틀의 개수와 전체 학생의 추천 결과가 추천받은 순서대로 주어졌을 때, 최종 후보가 누구인지 결정
*/

int n, g;  
int main(){
    cin >> n >> g; // 사진틀 개수, 전체 학생의 총 추천 횟수
    unordered_map<int, pair<int, int>> mp;
    
    for(int i = 0; i < g; i++){
        int m; cin >> m; 
        // map 보고 새로운 사람 ? -> 자리 남았나 확인
        // 자리 남았다면 추가
        // 자리 안남았다면 추천횟수 적은 것 중 오래된 것 삭제 -> 새로 삽입
        if(mp.find(m) == mp.end()){
            if(mp.size() < n){ // 자리 남음
                mp[m] = {1, i};
            }else{ // 자리 안남음
                int num = g; int wh = g; int id;
                for(auto mpp : mp){
                    if((mpp.second.first < num)|| 
                       (mpp.second.first == num && wh > mpp.second.second)){
                        num = mpp.second.first; 
                        wh = mpp.second.second; 
                        id = mpp.first;
                    }
                }
                mp.erase(id); // 기존 사람 지우고
                mp[m] = {1, i}; // 새로운 사람 추가
            }
        }
        
        // 기존 사람 -> 기존 추천 수 +1
        else{
            mp[m].first++; 
        }
    }
    
    vector<int> ans;
    // 최종 후보
    for(auto mpp : mp){
        ans.push_back(mpp.first); 
    }
    sort(ans.begin(), ans.end()); 
    
    for(int a: ans){
        cout << a << " ";
    }
    
}