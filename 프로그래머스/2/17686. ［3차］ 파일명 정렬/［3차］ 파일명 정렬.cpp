#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string getHead(string str){
    string head = "";
    for(int i = 0; i < str.size(); i++){
        if('0' <= str[i] && str[i] <= '9') break;
        head += tolower(str[i]);
    }
    return head;
}

int getNumber(string str, int headSize){
    string number = "";
    for(int i = headSize; i < str.size(); i++){
        if(!('0' <= str[i] && str[i] <= '9')) break;
        number += str[i];
    }
    return stoi(number);
}

vector<string> solution(vector<string> files) {
    
    // head과 number로 정렬, 순서 같으면 원래의 상대적 순서 보장
    stable_sort(files.begin(), files.end(), [](const auto&a, const auto&b){
        if(getHead(a) == getHead(b)){
            return getNumber(a, getHead(a).size()) < getNumber(b, getHead(b).size());
        }
        return getHead(a) < getHead(b); 
    });
        
    // 정렬된 파일 순서대로
    return files;
}