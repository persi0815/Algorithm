#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// 파일명은 100 글자 이내로, 영문 대소문자, 숫자, 공백(" "), 마침표("."), 빼기 부호("-")
vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    // head number tail로 나누어 저장 - 모두 소문자로 변경 
    vector< pair<pair<string, string>, string> > file; 
    for(auto f : files){
        string head = ""; string number = ""; string tail = ""; 
        for(int i = 0; i < f.size(); i++){
            if(isdigit(f[i]) && head == ""){
                head = f.substr(0, i); 
            }
            else if(!isdigit(f[i]) && head != "" && number == ""){
                number = f.substr(head.size(), i-head.size());
                tail = f.substr(i);
                break;
            }
        }
        // tail 부분이 없어서 number 부분에 못 넣었다면
        if(number == "") number = f.substr(head.size()); 
        
        file.push_back({{head, number}, tail});
    }
    
    
    // 정렬(나머지 그대로 유지)
    stable_sort(file.begin(), file.end(), [](const auto &a, const auto &b){
        // head는 모두 소문자로 변경한 뒤 비교
        string ah = ""; string bh = "";
        for(auto h : a.first.first) ah += tolower(h);
        for(auto h : b.first.first) bh += tolower(h);
        if(ah != bh) return ah < bh;
        
        // 앞의 0 제거한 뒤 수만 비교
        int an = stoi(a.first.second); int bn = stoi(b.first.second);
        if(an != bn) return an < bn;
    }); 
    
    // 정답 배열에 넣기
    for(auto f : file){
        answer.push_back(f.first.first+f.first.second+f.second);
    }
    
    return answer;
}