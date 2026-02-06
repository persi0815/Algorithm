#include <cstring>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int timeToMin(string time){
    int hour = stoi(time.substr(0, 2));
    int min = stoi(time.substr(3, 2));
    
    return hour*60+min;
}

int calculate(vector<int>& fees, int time){
    int default_time = fees[0];
    int default_fee = fees[1];
    int unit_time = fees[2];
    int unit_fee = fees[3];
    
    if(time <= default_time) return default_fee;
    else{
        return default_fee 
            + ceil((double)(time-default_time)/unit_time) * unit_fee;
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<int, int> total_time; // {번호, 총 시간}
    unordered_map<int, int> car_in; // {번호, 들어간 시각}
    for(string&r: records){
        stringstream ss(r);
        string time, car, order;
        ss >> time >> car >> order;
        
        int carNum = stoi(car);
        int curTime = timeToMin(time);
        // in 넣고, out시 가격 계산해서 넣기
        if(order == "IN"){ 
            car_in[carNum] = curTime;
        }else{
            total_time[carNum] += (curTime - car_in[carNum]);
            car_in.erase(carNum);
        }
    }
    // out 안된 차들 23:59로 계산해서 넣기
    for(auto & [carNum, inTime]: car_in){
        total_time[carNum] += (23*60+59 - inTime);
    }
    
    // 차량 번호로 오름차순되어 있음. map으로.
        
    // 차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로 
    for(auto & p: total_time){
        answer.push_back(calculate(fees, p.second)); 
        // cout  << p.first << " " <<  calculate(fees, p.second) << endl;
    }
    
    return answer;
}