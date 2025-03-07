#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, l; // 롤케이크의 길이
int loca[1000]; // 자를 수 있는 위치
int arr[1000]; // 원하는 조각 개수 (몇 번 자를지)

// 주어진 조각 개수(num)에 대해 가장 작은 조각의 길이의 최댓값을 찾는 함수
int solution(int num) {
    
    int left = 0, right = l, answer = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2; // 최소 조각 길이 후보
        int prev = 0; // 마지막으로 자른 위치
        int cut = 0; // 실제로 자른 횟수
        
        // 롤케이크의 각 자를 수 있는 위치에서 탐색
        for (int i = 0; i < m; i++) {  
            if (loca[i] - prev >= mid) { // 현재 조각이 mid 이상이면 자르기
                prev = loca[i]; // 마지막으로 자른 위치 업데이트
                cut++; // 자른 횟수 증가
            }
        }

        // 마지막 조각 확인
        // 원하는 횟수만큼 자르긴 했지만, 마지막 조각이 mid보다 작다면 유효하지 않음
        if (num == cut && l - prev < mid) { 
            cut = num - 1; // 마지막 조각이 너무 작으면 횟수를 하나 줄여서 실패 처리
        }

        if (cut < num) { // 원하는 횟수(num)보다 적게 잘랐다면, 더 작은 mid 시도
            right = mid - 1;
        } else { // 원하는 횟수 이상 잘랐다면, 가능한 정답 후보
            answer = mid; // 최댓값 갱신
            left = mid + 1; // 더 큰 mid 시도
        }
    }
    
    return answer;
}

int main() {
    cin >> n >> m >> l; // 조각 개수 목록 크기(n), 자를 수 있는 지점 개수(m), 롤케이크 길이(l)

    for (int i = 0; i < m; i++) cin >> loca[i]; // 자를 수 있는 위치 입력
    for (int i = 0; i < n; i++) cin >> arr[i]; // 원하는 조각 개수 입력
    
    // 각 조각 개수(num)에 대해 최소 조각의 최댓값을 구하고 출력
    for (int i = 0; i < n; i++) {
        cout << solution(arr[i]) << endl;
    }

    return 0;
}
