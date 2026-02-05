#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> sum;
    
    for(int start = 0; start <= elements.size()-1; start++){ // 시작 인덱스
        long long s = 0;
        for(int i = 0; i < elements.size(); i++){ // 길이
            s+=elements[(start + i) % elements.size()];
            sum.insert(s);
        }
    }
    return sum.size();
}