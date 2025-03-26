#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
수 묶기
- 양수는 큰 수끼리 곱
- 1은 그냥 더함
- 음수는 작은 수끼리 곱
- 음수 1개 남았고 0이 있으면 곱해서 무시
*/

int n; 
int res = 0;
vector<int> v;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int nn; cin >> nn; 
        v.push_back(nn);
    }
    
    sort(v.begin(), v.end(), greater<int>()); // 내림차순
    
    int idx = 0;

    // 양수 중 1보다 큰 애들끼리 곱
    while(idx + 1 < v.size() && v[idx] > 1 && v[idx + 1] > 1){
        res += v[idx] * v[idx + 1];
        idx += 2;
    }

    // 1은 더함
    while(idx < v.size() && v[idx] == 1){
        res += 1;
        idx++;
    }

    // 나머지 숫자들
    vector<int> sub(v.begin() + idx, v.end());

    vector<int> negatives;
    bool hasZero = false;

    for (int num : sub) {
        if (num == 0) hasZero = true;
        else if (num < 0) negatives.push_back(num);
        else res += num; // 남은 양수는 그냥 더함 (ex: 홀수 개의 양수 중 마지막 하나)
    }

    sort(negatives.begin(), negatives.end()); // 작은 음수부터

    int i = 0;
    while (i + 1 < negatives.size()) {
        res += negatives[i] * negatives[i + 1];
        i += 2;
    }

    // 음수 1개 남았을 경우
    if (i == negatives.size() - 1) {
        if (!hasZero) {
            res += negatives[i]; // 0 없으면 그냥 더함
        }
        // 0 있으면 곱해서 무시 (아무 것도 안 더함)
    }

    cout << res;
}
