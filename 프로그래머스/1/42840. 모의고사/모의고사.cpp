#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/* 
아래 패턴 반복해서 문제 찍음
1, 2, 3, 4, 5
2, 1, 2, 3, 2, 4, 2, 5
3, 3, 1, 1, 2, 2, 4, 4, 5, 5
=> 가장 많은 문제를 맞힌 사람? 
*/

// 정답 배열
vector<int> solution(vector<int> answers) { // 최대 10,000문제
    vector<int> answer; // 가장 많은 문제를 맞힌 사람
    
    // 찍는 패턴
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5}; 
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<pair<int, int>> corr(3);// 맞은 개수
    for(int i = 0; i < 3; i++){
        corr[i].second = i+1; corr[i].first = 0;
    }
    
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == first[i%first.size()]) corr[0].first++;
    }
    
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == second[i%second.size()]) corr[1].first++;
    }
    
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == third[i%third.size()]) corr[2].first++;
    }
    
    sort(corr.begin(), corr.end(), greater<pair<int, int>>()); 
    
    int best = corr[0].first;
    answer.push_back(corr[0].second); 
    for(int i = 1; i <= 2; i++){
        if(corr[i].first == best) answer.push_back(corr[i].second);
    }
    
    sort(answer.begin(), answer.end()); // 오름차순 정렬
    return answer;
}