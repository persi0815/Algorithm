#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
꼭대기에서 바닥까지 경로 잇기 -> 거쳐간 숫자의 합이 가장 큰 경우? 
대각선방향으로 한칸 오른쪽 or 왼쪽으로 만 이동 가능

*/

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size(); 

    vector<vector<int>> dp(height, vector<int>(height, 0)); 
    
    dp[0][0] = triangle[0][0]; 
    for(int i = 1; i < height; i++){
        for(int j = 0; j < i+1; j++){
            int left = 0; int right = 0;
            if(j-1>=0 && j-1<i) left = dp[i-1][j-1];
            if(j>=0 && j<i) right = dp[i-1][j];
            //cout << left << " " << right << endl;
            dp[i][j] = triangle[i][j] + max(left, right);
        }
    }
    
//     for(int i = 0; i < height; i++){
//         for(int j = 0; j <= i; j++){
//             cout << dp[i][j] << " ";
//         }
//         cout << endl;
//     }
    
    
    for(int i = 0; i < height; i++){
        answer = max(answer, dp[height-1][i]);
    }
    
    return answer;
}