#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string word) {
    int answer = 0;
    vector<char> alpha = {'A', 'E', 'I', 'O', 'U'};
    vector<int> weight = {781, 156, 31, 6, 1}; // 자리별 가중치 미리 계산

    for (int i = 0; i < word.size(); ++i) {
        // 현재 글자가 알파벳 리스트에서 몇 번째인지 찾기
        for (int j = 0; j < 5; ++j) {
            if (word[i] == alpha[j]) {
                answer += j * weight[i];
                cout << j << " " << weight[i] << " " << answer << endl;
                break;
            }
        }
        answer += 1; // 현재 글자 하나를 완성했으니까 +1
    }
    
    return answer;
}
