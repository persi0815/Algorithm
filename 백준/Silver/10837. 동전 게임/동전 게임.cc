#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <tuple>
using namespace std;

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int k, c; // 라운드 수, 입력의 개수

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k >> c; 

    unordered_set<pair<int, int>, pair_hash> visited;
    vector<tuple<int, int, int, bool>> ava; 
    ava.push_back({0, 0, 0, 1});
    visited.insert({0, 0});

    for(int r = 1; r <= k; r++){
        int size_before = ava.size();
        for(int s = size_before - 1; s >= 0; s--){
            //if(get<0>(ava[s]) != r-1 || get<3>(ava[s]) == false) break;
            if(get<0>(ava[s]) != r-1) break;
            if(get<3>(ava[s]) == false) continue;

            int yy = get<1>(ava[s]);
            int dd = get<2>(ava[s]);

            // 영희 앞면
            if(yy + 1 + (k - r) >= dd) {

                if (dd + 1 + (k - r) >= yy + 1) {
                    if (visited.insert({yy + 1, dd + 1}).second)
                        ava.push_back({r, yy + 1, dd + 1, true});
                } else {
                    if (visited.insert({yy + 1, dd + 1}).second)
                        ava.push_back({r, yy + 1, dd + 1, false});
                }

                if (dd + (k - r) >= yy + 1) {
                    if (visited.insert({yy + 1, dd}).second)
                        ava.push_back({r, yy + 1, dd, true});
                } else {
                    if (visited.insert({yy + 1, dd}).second)
                        ava.push_back({r, yy + 1, dd, false});
                }
                
                
            }

            // 영희 뒷면
            if(yy + (k - r) >= dd) {

                if (dd + 1 + (k - r) >= yy) {
                    if (visited.insert({yy, dd + 1}).second)
                        ava.push_back({r, yy, dd + 1, true});
                } else {
                    if (visited.insert({yy, dd + 1}).second)
                        ava.push_back({r, yy, dd + 1, false});
                }

                if (dd + (k - r) >= yy) {
                    if (visited.insert({yy, dd}).second)
                        ava.push_back({r, yy, dd, true});
                } else {
                    if (visited.insert({yy, dd}).second)
                        ava.push_back({r, yy, dd, false});
                }
            }
        }
    }

    // for(int i = 0; i < ava.size(); i++){
    //     cout << get<0>(ava[i]) << " " << get<1>(ava[i]) << " " << get<2>(ava[i]) << " " << get<3>(ava[i]) << endl;
    // }

    for(int i = 0; i < c; i++){
        int m, n; cin >> m >> n;
        if (visited.count({m, n})) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}
