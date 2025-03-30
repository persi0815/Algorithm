#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_map>
using namespace std;

/* 통계학
n개의 수를 대표하는 기본 통계값 
산술, 중앙, 최빈, 범위
-> n개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램!
*/
double n;
double total = 0; // 산술
vector<int> v;
unordered_map<int, int> m; // 최빈 
pair<int, int> mm = {0, 0};
vector<int> mmm;
int ma = -INT_MAX; int mi = INT_MAX; // 범위

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);     
    
    cin >> n; // 500,000
    
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        total += a;
        v.push_back(a);
        m[a]++; 
        if(m[a] > mm.second) {
            mm.first = a;
            mm.second = m[a];
            mmm.clear();
            mmm.push_back(a);
        }
        else if(m[a] == mm.second){
            mmm.push_back(a);
        }
        if(ma < a) ma = a;
        if(mi > a) mi = a;
    }
    
    sort(v.begin(), v.end());

    int res = round(total / n);
    if(res == -0) cout << 0 << endl;
    else cout << round(total / n) << endl; // 산술
    
    cout << v[n/2] << endl; // 중앙
    
    if(mmm.size() == 1){
        cout << mm.first << endl; // 최빈1
    }
    else {
        sort(mmm.begin(), mmm.end());
        cout << mmm[1] << endl; // 최빈2
    }
    
    cout << ma - mi << endl; // 범

}