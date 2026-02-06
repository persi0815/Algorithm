#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// i를 n진법으로 바꾸어 리턴 (10이상은 알파벳으로)
string digits = "0123456789ABCDEF";
string change(int i, int n){
    if(i == 0) return "0";
    
    string res = "";
    while(i > 0){
        int r = i % n;
        res += digits[r];
        i /= n;
    }
    
    // 역순으로
    reverse(res.begin(), res.end());
    return res;
}

// 진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p
string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string totalNum = ""; // 진법 변환한 수 다 합친 결과
    int current = 0;
    while(totalNum.length() < m*t){
        totalNum += change(current++, n);
    }
    
    // 튜브 결과 넣기
    for(int i = 0; i < t; i++){
        answer += totalNum[m*i+(p-1)];
    }
    
    return answer;
}