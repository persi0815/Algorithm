#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

int diff(string start, string end){
    int startHour = stoi(start.substr(0, 2)); 
    int startMin = stoi(start.substr(3, 2)); 
    int endHour = stoi(end.substr(0, 2));
    int endMin = stoi(end.substr(3, 2));
    
    return endHour*60 + endMin - (startHour*60 + startMin);
}

string make(string original){
    // # 나오면 해당 계이름 소문자로 만들기 ex. C# -> c
    string res = "";
    for(int i = 0; i < original.size(); i++){
        char o = original[i]; 
        if(i+1 < original.size() && original[i+1] == '#') {
            res += tolower(o); i++;
        }
        else res += o;
    }
    return res;
}

// 기억한 멜로디를 담은 문자열 m과 방송된 곡의 정보를 담고 있는 배열 musicinfos
// 음악 제목, 재생이 시작되고 끝난 시각, 음악 제목, 악보 
string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int maxDuration = 0; 
    
    // # 나오면 해당 계이름 소문자로 만들기 ex. C# -> c
    m = make(m);
    // cout << "m " << m << endl;
    
    for(int i = 0; i < musicinfos.size(); i++){ // 100
        stringstream ss(musicinfos[i]); 
        string start, end, name, sheet; 
        getline(ss, start, ',');
        getline(ss, end, ',');
        getline(ss, name, ',');
        getline(ss, sheet, ',');
        sheet = make(sheet); // 악보 치환
        // cout << "sheet " << sheet << endl;
        
        int duration = diff(start, end); // 분으로 기간 추출
        
        // 실제 재생된 전체 멜로디 문자열 생성
        string played = "";
        for(int j = 0; j < duration; j++){ // 24*60*1439
            played += sheet[j % sheet.size()];
        }
        // cout << "played " << played << endl;
        
        // 문자열 찾기
        if(played.find(m) != string::npos){ // 24*60*1439 * 1439
            if(maxDuration < duration) { // 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환
                maxDuration = duration; answer = name;
            }
        }
    }
    return answer;
    
}