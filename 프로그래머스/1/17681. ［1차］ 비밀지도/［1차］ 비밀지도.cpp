#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getBinary(int a, int size){
    string res = "";
    while(a > 0){
        res += (a%2 + '0'); // to char
        a /= 2;
    }
    // 1101 -> 11010 -> 01011
    res += string(size - res.size(), '0');
    reverse(res.begin(), res.end());
    return res;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<char>> res(n, vector<char>(n));
    // 이진수로 바꿔서 넣기
    for(int i = 0; i < arr1.size(); i++){
        string binary = getBinary(arr1[i], n);
        for(int j = 0; j < n; j++){
            res[i][j] = binary[j];
        }
    }
    
    for(int i = 0; i < arr2.size(); i++){
        string binary = getBinary(arr2[i], n);
        for(int j = 0; j < n; j++){
            // 기존에 0이었던 부분만 1로 변경
            // 기존에 1이었던 부분은 1 유지
            if(res[i][j] == '0') res[i][j] = binary[j];
        }
    }
    
    // 지도의 각 가로줄에서 벽 부분을 1, 공백 부분을 0으로 부호화했을 때 얻어지는 이진수에 해당하는 값의 배열
    for(int i = 0; i < n; i++){
        string str = "";
        for(int j = 0; j < n; j++){
            if(res[i][j] == '0') str += ' ';
            else str += '#';
        }
        answer.push_back(str);
    }
    
    return answer;
}