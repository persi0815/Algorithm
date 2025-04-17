#include <string>
#include <vector>
#include <queue>
#include <unordered_map> 
#include <sstream>
#include <iostream>
using namespace std;
/*
명령어에 따라 작업 수행
비어있는데 삭제하라고 하면 무시
최종 결과가 비어있다면 [0,0] 비어잇지 않다면 [최대값, 최솟값]
*/
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> max_heap; 
    priority_queue<int, vector<int>, greater<int>> min_heap; 
    
    unordered_map<int, int> m; // 상태 파악할 수 있는 map {숫쟈, 남은 개수}
    
    for(int i = 0; i < operations.size(); i++){
        string order = operations[i];
        stringstream ss(order); // 공백 기준으로 분리
        string o; ss >> o; // 명령어
        string ns; ss >> ns; // "-1" 이렇게 하나로 받아야 함
        
        if(o == "I"){ // 삽입
            int n = stoi(ns);
            max_heap.push(n); min_heap.push(n);
            m[n]++;
            //cout << "insert : " << n << " " << m[n] << endl;
        }
        else{ // 삭제
            if(ns == "-1"){ // 최솟값 삭제
                bool flag = false;
                while(!min_heap.empty()){
                    int num = min_heap.top(); 
                    if(m.find(num) == m.end()){
                        min_heap.pop();
                    } else {
                        flag = true; break;
                    }
                }
                if(flag){
                    int num = min_heap.top(); 
                    //cout << "del: " << num << " " << m[num] << endl;
                    if(--m[num] == 0) m.erase(num); 
                }

                
            }
            else{ // 최댓값 삭제
                bool flag = false;
                while(!max_heap.empty()){
                    int num = max_heap.top(); 
                    if(m.find(num) == m.end()){
                        max_heap.pop();
                    } else {
                        flag = true; break;
                    }
                }
                if(flag){
                    int num = max_heap.top(); 
                    //cout << "del: " << num << " " << m[num] << endl;
                    if(--m[num] == 0) m.erase(num); 
                }
                
            }
            
        }
        
    }
    
    
    // 최댓값, 최솟값 찾아 넣기
    if(m.size() == 0) answer = {0, 0}; 
    else{
        while(m.size() != 0){
            int num = max_heap.top(); 
            if(m.find(num) == m.end()){
                max_heap.pop();
            } else break;
        }
        int maxx = max_heap.top();
        
        while(m.size() != 0){
            int num = min_heap.top(); 
            if(m.find(num) == m.end()){
                min_heap.pop();
            } else break;
        }
        int minn = min_heap.top(); 
        
        answer = {maxx, minn};
        
    }
    
    
    return answer;
}