#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;
/*
길이가 m인 수열을 모두 구하기
- n개의 자연수 중 m개 고르기
- 수열은 비 내림차순. 오름 + 같아도 됨
문제의 조건 만족하는 수열 출력. 
*/

int n, m; 
void make(vector<int>& v, vector<int>& res, int st){
    if(res.size() == m){ // 원하는 원소만큼 고름
        for(int i = 0; i < m; i++){
            cout << res[i] << " ";
        }
        cout << '\n'; 
        return;
    }

    int bef = -1;
    for(int i = st; i < v.size(); i++){ // 수 중복 가능
        if(bef == v[i]) continue; // 이전의 것과 중복 안되도록!!
        res.push_back(v[i]);
        make(v, res, i+1);
        bef = res.back(); // 같은 깊이에서 중복되는 숫자 제거
        res.pop_back(); 
        
    }
}

int main(){
    cin >> n >> m; 
    vector<int> v;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end()); // 오름차순
    vector<int> res;
    make(v, res, 0); 
    
}

