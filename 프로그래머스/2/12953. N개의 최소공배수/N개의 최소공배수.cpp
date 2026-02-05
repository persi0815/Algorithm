#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> arr) { // n개의 수의 최소공배수 구하기
    int answer = 1;
    
    vector<int> arr2;
    long long multi = 1; // 나누는 값
    for(int i = 2; i <= *max_element(arr.begin(), arr.end()); i++){ // 10
        
        while(true){
            int avail = 0;  arr2 = arr;  // 초기화
            for(int a = 0; a < arr.size(); a++){ // 15
                if(arr[a] % i == 0){
                    arr2[a] = arr[a] / i; // 몫 저장
                    avail++;
                }
            }
            if(avail > 0){
                arr = arr2; multi *= i;
            } else break;
        } 
    }
    
    for(int i = 0; i < arr.size(); i++){
        answer *= arr[i];
    }
    answer *= multi; 
    
    return answer;
}