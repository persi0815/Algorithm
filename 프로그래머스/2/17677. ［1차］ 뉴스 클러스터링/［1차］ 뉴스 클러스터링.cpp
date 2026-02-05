#include <string>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    // 두 개씩 자르기
    vector<string> s1; 
    vector<string> s2; 
    
    string str; 
    for(int i = 0; i < str1.size()-1; i++){
        str = "";
        if(('A' <= str1[i] && str1[i] <= 'Z') || ('a' <= str1[i] && str1[i] <= 'z'))
            str += toupper(str1[i]);
        else continue;
        if(('A' <= str1[i+1] && str1[i+1] <= 'Z') || ('a' <= str1[i+1] && str1[i+1] <= 'z'))
            str += toupper(str1[i+1]); 
        else continue;
        s1.push_back(str);
    }
    for(int i = 0; i < str2.size()-1; i++){
        str = "";
        if(('A' <= str2[i] && str2[i] <= 'Z') || ('a' <= str2[i] && str2[i] <= 'z'))
            str += toupper(str2[i]);
        else continue;
        if(('A' <= str2[i+1] && str2[i+1] <= 'Z') || ('a' <= str2[i+1] && str2[i+1] <= 'z'))
            str += toupper(str2[i+1]);
        else continue;
        s2.push_back(str);
    }
    
    // 둘다 정렬
    if(s1.size() == 0 && s2.size() == 0){
        return 65536;
    }else{
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
    }
    
    // 둘이 같은거 있으면 교집합에 넣기
    vector<string> inter;
    int s1Idx = 0; int s2Idx = 0; 
    while(s1Idx < s1.size() && s2Idx < s2.size()){
        if(s1[s1Idx] == s2[s2Idx]){
            inter.push_back(s1[s1Idx]); s1Idx++; s2Idx++;
        } else if(s1[s1Idx] < s2[s2Idx]){
            s1Idx++;
        }else{
            s2Idx++;
        }
    }
    
    // 둘이 더하고 교집합꺼 빼기 -> 합집합
    int orSize = s1.size() + s2.size() - inter.size();
    
    // 교집합 크기 / 합집합 크기 * 65536    
    return floor(((double)inter.size() / (double)orSize) * 65536);
}