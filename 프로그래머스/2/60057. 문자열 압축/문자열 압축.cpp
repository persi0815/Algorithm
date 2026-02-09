#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(string s) {
    int answer = s.size(); // 최악의 길이
    
    // 완탐으로 잘라서 계산 후 크기 갱신
    for(int siz = 1; siz <= s.size()/2; siz++){
        string result = "";
        string prev = s.substr(0, siz); // 첫 번째 조각
        int count = 1;
        // 크기대로 잘라서 prev랑 curr 비교
        for(int id = siz; id < s.size(); id+=siz){
            string curr = s.substr(id, siz);
            // 이전꺼랑 같으면
            if(curr == prev) {
                count ++;
            }
            // 이전꺼랑 다르면
            else{
                if(count > 1){
                    result += to_string(count); // 넣기
                }
                result += prev;
                
                // 새로운 후보 설정
                prev = curr; 
                count = 1;
            }
        }
         
        // 남은게 있다면
        if(count > 1) result += to_string(count);
        result += prev;
        
        // 결과 갱신
        answer = min(answer, (int)result.size());
    }
    
    // 문자열을 잘라 압축하여 표현한 문자열 중 가장 짧은 것의 길이
    return answer;
}