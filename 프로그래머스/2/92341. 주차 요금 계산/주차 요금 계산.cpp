#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

int to_minute(string ht){
    int hour = stoi(ht.substr(0, 2));
    int minute = stoi(ht.substr(3, 2)); 
    return hour * 60 + minute; 
}

vector<int> solution(vector<int> fees, vector<string> records) { 
    int default_time = fees[0]; 
    int default_cost = fees[1]; 
    int piece_time = fees[2]; 
    int piece_cost = fees[3]; 
    
    // 주차장에 있는 차들
    unordered_map<string, int> garage; // {차번호, 입차 시간(m)}
    // 시간 누적
    unordered_map<string, int> sum_time; // {차번호, 누적 주차 시간}
    // 비용(최종)
    vector<pair<string, int>> sum_cost; // {차번호, 최종 비용} 
    
    // records 시각(HH:MM) 차량번호(0000) 내역(IN/OUT)
    for(auto r: records){
        stringstream ss(r); 
        string time, car, order; 
        ss >> time >> car >> order; 
        int minute = to_minute(time);
        
        if(order == "IN"){
            // 주차장에 넣기
            garage[car] = minute;
        }else{
            // 누적 주차 시간 계산 -> 갱신
             sum_time[car] += minute - garage[car]; 
            
            // 주차장에서 빼기
            garage.erase(car); 
        }
    }
    // 아직 출차 안된 차들 23:59 기준 출차됨으로 처리
    for(auto g : garage){
        sum_time[g.first] += to_minute("23:59") - g.second; 
    }
    
    // 누적 주차 시간 -> 최종 비용 계산
    for(auto st : sum_time){
        int t = st.second; 
        int c = 0;
        if(t > default_time){
            c += default_cost; 
            t -= default_time; 
            if(t % piece_time != 0){
                c += piece_cost*(t/piece_time + 1);
            }else{
                c += piece_cost*(t/piece_time);
            }
        }else {
            c += default_cost;
        }
            
        sum_cost.push_back({st.first, c}); 
    }
    
    // 정렬 -> 결과 배열에 삽입
    sort(sum_cost.begin(), sum_cost.end(), [](auto & a, auto &b){
        if(a.first != b.first) return a.first < b.first; // 차량 번호 오름차순
    }); 
    vector<int> cost; 
    for(auto sc : sum_cost){
        cost.push_back(sc.second); 
    }
    
    
    // 차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로 정수 배열에 담아서 return 
    return cost;
}