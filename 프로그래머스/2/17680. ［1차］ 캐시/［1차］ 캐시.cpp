#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <cctype>

using namespace std;

// DB 캐시를 적용할 때 캐시 크기에 따른 실행시간 측정
int solution(int cacheSize, vector<string> cities) { // 도시 10만개
    int answer = 0;
    
    unordered_map<string, int> city_cache; // 캐시
        
    priority_queue<
        pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>
    > min_heap; // 무엇을 삭제해야 하는지 알기 위한 용도. 이미 제거된 값이 존재할 수 있음

    int time = 0;
    for(auto city_raw : cities){
        // 모두 소문자로 바꾸기
        string city = "";
        for(auto c : city_raw){
            city += tolower(c);
        }
        if(cacheSize == 0) answer += 5;
        
        // 존재하는지 파악. 없다면 삽입
        else if(city_cache.find(city) == city_cache.end()){ // miss -> 삽입
            
            if(city_cache.size() >= cacheSize){ // 캐시에 여유분 없으니 하나 빼고 넣어야 함
                // 제거할 key 찾기
                while(!min_heap.empty()){
                    auto t = min_heap.top(); 
                    min_heap.pop(); 
                    // 만약 힙에서 꺼낸 도시가 캐시에 존재하고, 타임스탬프까지 완벽히 일치한다면
                    if(city_cache.find(t.second) != city_cache.end() 
                      && city_cache[t.second] == t.first){ 
                        city_cache.erase(t.second); // 제거
                        break;
                    }
                }
            }
            answer += 5;
            // cout << "miss: " << city << " " << time << " " << answer << endl;
        }
        else{ // hit
            answer += 1;
            // cout << "hit: " << city << " " << time <<" " << answer << endl;
        }
        
        // 삽입 OR 시간 갱신
        city_cache[city] = time; 
        min_heap.push({time, city});
        
        time++;
    }
    
    // 총 실행시간
    return answer ;
}