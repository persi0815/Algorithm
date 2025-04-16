#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> clothesCount;

    // 종류별 옷 개수 저장
    for (auto& item : clothes) {
        string type = item[1];
        clothesCount[type]++;
    }

    int answer = 1;

    // 각 종류마다 (입는 경우 수 + 안 입는 경우 1)씩 곱함
    for (auto& kv : clothesCount) {
        answer *= (kv.second + 1);
    }

    return answer - 1; // 아무것도 안 입는 경우 제외
}
