#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 각 조합(비트마스크)의 등장 횟수를 저장
unordered_map<int, int> comboCount;

// currentOrder: 손님이 주문한 메뉴 비트
// mask: 현재까지 선택된 메뉴 조합 비트
// start: 탐색 시작 인덱스
// count: 현재 선택된 메뉴 개수
// target: 뽑아야 하는 메뉴 개수 (course)
void findCombos(int currentOrder, int mask, int start, int count, int target) {
    if (count == target) {
        comboCount[mask]++;
        return;
    }
    for (int i = start; i < 26; i++) {
        // 손님의 주문 내역(currentOrder)에 i번째 메뉴가 포함되어 있다면 선택
        if (currentOrder & (1 << i)) {
            findCombos(currentOrder, mask | (1 << i), i + 1, count + 1, target);
        }
    }
}

string toMenu(int menu){
    string ans = "";
    for(int i = 0; i < 26; i++){
        if(menu & (1 << i)) ans += (char)('A'+i);
    }
    return ans;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // orders의 course 크기에 맞는 모든 부분집합 추출
    for (int cSize : course) {
        comboCount.clear(); 
        
        // 모든 주문에 대해 cSize 크기의 조합을 생성하여 카운트
        for(string & o : orders){
            int orderBit = 0;
            for (char c : o) orderBit |= (1 << (c - 'A'));
            findCombos(orderBit, 0, 0, 0, cSize);
        }
        
        // 각 cSize에서 가장 많이 주문한 횟수 구하기
        int maxCount = 0; 
        for(auto& c: comboCount){
            maxCount = max(maxCount, c.second);
        }
        
        // 가장 많이 주문한 메뉴 넣기
        if(maxCount >= 2){
            for(auto& c: comboCount){
                if(c.second == maxCount) answer.push_back(toMenu(c.first));
            }
        }
    }

    // 사전순으로 오름차순 정렬
    sort(answer.begin(), answer.end());
    return answer;
}