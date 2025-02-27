#include <iostream>
#include<vector>
#include <algorithm> 
using namespace std;
// 배열에서 각각 한개 뽑아 곱하는 과정 반복. 대신 뽑았던거 또 못 뽑아. 
// 해당 값 누적하여 더함. 최종적으로 누적된 값이 최소가 되어야함. 
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    for(int i = 0; i< A.size(); i++){
        answer += A[i] * B[i];
    }
    

    return answer; // 최종적으로 누적된 값
}