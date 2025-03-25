#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/* 어린왕자
행성계 진입/이탈 횟수 구하자. 

*/
int t;

// 중심과의 거리가 반지름보다 짧다. 
bool isInside(int x, int y, int cx, int cy, int r) {
    return (x - cx) * (x - cx) + (y - cy) * (y - cy) < r * r;
}

int main(){
    cin >> t;
    while(t--){
        //int result = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; // 출발, 도착지
        int n;
        cin >> n; // 행성의 개수
        unordered_map<int, tuple<int, int, int>> m;
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            int cx, cy, r; 
            cin >> cx >> cy >> r; // 중점, 반지름
            m[i] = {cx, cy, r};
        }
        
        // 로직
        // 뚫고 나가야 하는 것 -> 출발지가 원 안에 있는지 확인
        for(auto mm: m){
            auto t = mm.second;
            int cx = get<0>(t); int cy =get<1>(t); int r = get<2>(t);
            if(isInside(x1, y1, cx, cy, r)) s.insert(mm.first);
        }
        
        // 진입해야 하는 것 -> 도착지가 원 안에 있는지 확인
        for(auto mm: m){
            auto t = mm.second;
            int cx = get<0>(t); int cy =get<1>(t); int r = get<2>(t);
            if(isInside(x2, y2, cx, cy, r)){
                if(s.find(mm.first) != s.end()) s.erase(mm.first);
                else s.insert(mm.first);
            }
        }
        
        // 겹치는거 빼고 나머지 개수 더하면 되는거 아닝가
        
        
        // 각 테케에 대해 어린왕자가 거쳐야 할 최소의 행성계 진입/이탈 횟수
        cout << s.size() << endl;
    
    } // 테케 반복
    
}
