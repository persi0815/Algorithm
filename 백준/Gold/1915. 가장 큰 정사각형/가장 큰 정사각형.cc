#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* 가장 큰 정사각형
1로된 가장 큰 정사각형의 넓이를 구하라. 
인접한 곳들만 보고 현재 위치의 값을 알아내야 함. 
배열에 넓이 저장 x 길이 저장 o -> 방향 두개 동시에 고려해야 함. 
배열에 해당 장소까지 이어지는 가장 짧은 길이 저장!!
문제는 가장 '큰'을 원했지만, 반대로 가능한 가장 '짧은' 변의 길이를 구해야했음
어떤 요소가 답을 결정하는지 명확히 파악하자. 
*/
int main() {
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        string str; 
        cin >> str;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = str[j - 1] - '0';
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 1) {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                res = max(res, dp[i][j]);
            }
        }
    }


    cout << res * res;
}
