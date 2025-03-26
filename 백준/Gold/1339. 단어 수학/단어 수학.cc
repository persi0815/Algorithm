#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
/*단어 수학
각 알파벳 대문자를 0~9 중 하나로 바꿔서 n개의 수를 합하는 문제
같은 알파벳은 같은 수로. 두 개 이상의 알파벳이 같은 수로 바꿔지면 안됨. 
중복되는 알파벳을 높은 수로 + 자리수가 높은걸 큰 수로
n개가 주어졌을 때 그 수의 합을 최대로 만들자. 

가중치를 따로 계산하면 안되나 -> 가중치 별 정렬
*/
int n;
unordered_map<int, int> m;
vector<int> v;
int res = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        int siz = str.size();
        int idx = 0;
        while(siz--){
            m[str[idx++]] += pow(10, siz);
        }
    }
    
    for(auto mm: m){
        v.push_back(mm.second);
    }
    sort(v.begin(), v.end(), greater<int>()); // 내림차순 정렬
    
    int num = 9;
    for(int i = 0; i < v.size(); i++){
        res += num * v[i];
        //cout << res << " " << num << " " << v[i] << endl;
        num--;
        
    }
    
    cout << res;
    
}