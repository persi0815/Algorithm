#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> nums = 
{{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
int solution(string s) {
    int answer = 0;
    
    string n = "";
    for(auto& ss : s){
        if(isdigit(ss)) {
            if(!n.empty()){
                answer = answer * 10 + nums[n];
                n = "";
            }
            answer = answer*10 + (ss-'0');
        }
        else{
            if(nums.find(n) != nums.end()){
                answer = answer * 10 + nums[n];
                n = "";
            }
            n += ss;
        }
    }
    // 마지막
    if(!n.empty()){
        answer = answer * 10 + nums[n];
    }
    
    // 원래 의미하는 숫자 리턴
    return answer;
}