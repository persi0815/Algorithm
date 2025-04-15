#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
생산성과 영향력을 나타내는 값인 h를 구하려고 함. 
n편중 h번 이상 인용된 논문이 h편 이상. 나머지 논문이 h번 이하. 
-> h의 최댓값이 지표값
=> 탐색 -> 완탐/이진/분할
*/ 

int binary_search(vector<int>& citations){
    int answer = 0;
    int n = citations.size();
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int h = n - mid; // 현재 위치부터 끝까지 논문 수

        if (citations[mid] >= h) {
            answer = h; // h-index 후보
            right = mid - 1; // 더 왼쪽에서 더 큰 h가 있는지 탐색
        } else {
            left = mid + 1;
        }
    }
    return answer;
}


// 인용횟수 담은 배열. h-idx를 return!
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end()); // 오름차순
    
    answer = binary_search(citations);
    
    return answer; // 지표의 최댓값
}