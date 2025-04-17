#include <string>
#include <vector>

using namespace std;
/*
중앙이 노란색, 테두리 한줄이 갈색
격자의 개수는 기억했지만, 전체 카펫의 크기 기억x
=> 카펫의 가로, 세로 크기를 순서대로 배열에 담기 가로 >= 세로
*/

// 격자의 개수 
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // yellow의 약수 구하기
    for(int h = 1; h*h <= yellow; h++){
        if(yellow % h == 0) {
            int l = yellow/h;
            if(l*2 + h*2 + 4 == brown){
                answer = {l+2, h+2};
                break;
            }
        }
    }
    
    return answer;
}