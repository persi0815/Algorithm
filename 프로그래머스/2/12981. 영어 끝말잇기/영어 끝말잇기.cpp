#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
// 제대로 끝말잇기하는지 -> 이전의 끝 알파벳 저장
// 반복되진 않는지 -> set
vector<int> solution(int n, vector<string> words) {
    unordered_set<string> word;
    
    int turn = 1; char bef = words[0][0];
    for(int i = 0; i < words.size(); i++){
        if(words[i][0] != bef){ // 이어가지 못함 탈락
            return {i % n + 1, i/n + 1};
        }else if(word.count(words[i])){ // 중복됨
            return {i % n + 1, i/n + 1};
        } else { // 이어가기
            bef = words[i][words[i].size()-1];
            word.insert(words[i]);
        }
    }

    // 가장 먼저 탈락하는 사람의 번호, 자신의 몇 번째에 탈락하는지 => {번호, 차례}
    return {0, 0};
}