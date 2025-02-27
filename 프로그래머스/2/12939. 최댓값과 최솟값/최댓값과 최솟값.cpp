#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> num;
    
    stringstream ss(s);
    string number;
    while(ss >> number){
        num.push_back(stoi(number));
    }
        
    sort(num.begin(), num.end());
    
    string small = to_string(num[0]);
    string big = to_string(num[num.size()-1]);
    
    answer = small + " " + big;
    
    return answer; // 최소 최대
}