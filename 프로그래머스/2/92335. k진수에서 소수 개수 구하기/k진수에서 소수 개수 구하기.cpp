#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

bool isPrime(long long x){
    if(x < 2) return false;
    for(long long i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    // n을 k진수로 바꾸기
    stack<long long> st;
    while(n > 0){
        st.push(n%k);
        n /= k;
    }
    vector<long long> num; 
    while(!st.empty()){
        num.push_back(st.top()); st.pop();
    }
    
    // 0을 기준으로 split
    long long m = 0;
    vector<long long> candidate;
    for(long long i = 0; i < num.size(); i++){
        if(num[i] == 0 && m != 0){
            candidate.push_back(m);
            m = 0;
        }else{
            m = m*10 + num[i];
        }
    }
    if(m != 0) candidate.push_back(m);
    
    // 소수인지 판별
    // 메모리 때문에 에라토스테네스의체 불가
    // int maxx = *max_element(candidate.begin(), candidate.end());
    // vector<bool> prime(maxx+1, true);
    // prime[1] = false; 
    // for(int i = 2; i*i <= maxx; i++){
    //     for(int j = i*i; j <= maxx; j+= i){
    //         prime[j] = false;
    //     }
    // }
    
    // 소수 개수 리턴
    // cout << "res" << endl;
    for(auto & c: candidate){
        if(isPrime(c)) {
            answer++; 
        }
    }
    return answer;
}