#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<int>> res;
vector<int> solution(vector<string> gems) {

    // 종류 개수 구하기
    unordered_set<string> type; 
    for(auto& g: gems){
        type.insert(g);
    }
    int typeNum = type.size(); 
    
    // 구간 구하기
    int startId = 0; int endId = gems.size()-1;
    int start = 0; int end = 0; 
    unordered_map<string, int> gCnt; 
    gCnt[gems[0]]++;
    while(start <= end && end < gems.size()){ 
        if(gCnt.size() == typeNum){ // 가능한 상태면 start++
            // 갱신
            if(endId-startId > end-start)  {
                endId = end; startId = start;
            }
            
            // 이동
            gCnt[gems[start]]--;
            if(gCnt[gems[start]] == 0) gCnt.erase(gems[start]); // 없으면 제거
            start++;
        }else{ // 전부 있을 때까지 end++
            // 이동
            end++; 
            if(end >= gems.size()) break;
            gCnt[gems[end]]++;
        }
    }

    // 모든 보석을 하나 이상 포함하는 가장 짧은 구간을 찾아서 return
    // {시작 진열대 번호, 끝 진열대 번호}
    return {startId+1, endId+1};
}