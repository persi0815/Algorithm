#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 비트마스크로 유일성 확인
bool isUnique(int mask, const vector<vector<string>>& relation) {
    unordered_set<string> s;
    int rowSize = relation.size();
    int colSize = relation[0].size();

    for (int r = 0; r < rowSize; r++) { // 20
        string temp = "";
        for (int c = 0; c < colSize; c++) { // 8
            if (mask & (1 << c)) { // 해당 컬럼이 비트에 포함되어 있다면
                temp += relation[r][c] + "|";
            }
        }
        if (s.count(temp)) return false;
        s.insert(temp);
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int colSize = relation[0].size();
    vector<int> candidateKeys;

    // 모든 조합을 비트마스크로 표현 (1부터 2^colSize - 1까지)
    for (int mask = 1; mask < (1 << colSize); mask++) { 
        
        // 1. 유일성 체크
        if (!isUnique(mask, relation)) continue;

        // 2. 최소성 체크 (이미 찾은 후보키가 현재 mask의 부분집합인지 확인)
        bool minimality = true;
        for (int key : candidateKeys) {
            if ((key & mask) == key) { // 이미 찾은 key가 현재 mask에 포함됨
                minimality = false;
                break;
            }
        }

        if (minimality) candidateKeys.push_back(mask);
    }

    return candidateKeys.size();
}