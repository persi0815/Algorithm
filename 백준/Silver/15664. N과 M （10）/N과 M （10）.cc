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
int bef = -1;
void make(vector<int>& v, vector<int>& res, int st){
    if(res.size() == m){ // 원하는 원소만큼 고름
        for(int i = 0; i < m; i++){
            cout << res[i] << " ";
        }
        cout << '\n'; 
        return;
    }
    
    for(int i = st; i < v.size(); i++){ // 수 중복 가능
        if(bef == v[i]) continue;
        res.push_back(v[i]);
        // for(int r:res) cout << r << " ";
        // cout << endl;
        make(v, res, i+1);
        bef = res.back();
        res.pop_back(); 
        
    }
}

int main(){
    cin >> n >> m; 
    vector<int> v;
    //unordered_set<int> s; 
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.push_back(num);
        // if(s.find(num) == s.end()) { // 중복 안되도록
        //       
        //     s.insert(num); 
        // }
    }

    //for(int vv:v) cout << vv << " ";
    //cout << endl;
    
    sort(v.begin(), v.end()); // 오름차순
    vector<int> res;
    make(v, res, 0); 
    
}

