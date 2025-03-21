#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
빈 문자열 -> 더미 추가해서 포화 이진트리로 만듦(루트 고정) 
-> 왼에서 오로 순서대로 살펴봄. 높이는 순서에 영향 x
-> 살펴본게 더미 노드라면 문자열 뒤에 0 추가. 아니라면 1 추가
-> 이진수를 십진수로 변환. 

수가 주어졌을 때, 하나의 이진트리로 해당 수를 표현할 수 있는지 알고 싶다. 

1. 수 -> 이진수로 바꾸기 (이진수 길이는 1, 3, 7, 15..)
2. 가운데 수가 1이어야 함
3. 
*/

vector<int> ava_length;
bool flag = true;
vector<long long> multi(51);
void make_multi(){
    multi[0] = 1;
    for(int i = 1; i <= 50; i++){
        multi[i] = multi[i-1] * 2;
    }
    reverse(multi.begin(), multi.end()); // 내림차순
}

void make_length(){
    for (int i = 1; i <= 52; i++) {
        int len = (1 << i) - 1;
        ava_length.push_back(len);
        if (len > 127) break;
    }
}

vector<int> make_binary(long long number, int& f, int& l){
    vector<int> bin(51, 0);
    for(int i = 0; i <= 50; i++){
        if(number >= multi[i]){
            if(!f) f = 50 - i; 
            l = 50 - i;
            number -= multi[i]; bin[i] = 1;
        }
        else bin[i] = 0;
    }
    
    reverse(bin.begin(), bin.end()); // 다시 작은 것 부터
    return bin;
}

void last_check(vector<int>& bin, int start, int end, int r){
    // mid가 0인데, 그 아래에 1이 있으면 안됨. 
    if(flag == false) return;
    if(start > end) return; // 잊지 말자
    
    int mid = (start + end)/2; 
    if(bin[mid] == 0){
        last_check(bin, start, mid - 1, 0);
        last_check(bin, mid + 1, end, 0);
    }else{
        if(r == 0) {
            flag = false; return;
        }
        last_check(bin, start, mid - 1, 1);
        last_check(bin, mid + 1, end, 1);
    }
    
}

int check(long long number){
    int avail = 0; flag = true;
    // 이진수 만들기 -> 길이 확인하기 -> 맨 마지막 1의 위치로 가능성 판단하기
    int first_idx = 0; int last_idx = 0;
    vector<int> bin = make_binary(number, first_idx, last_idx);
    bin.resize(127, 0);
    
    // 길이 바꿔가며 가능한지 확인
    vector<int> av_l;
    for(int i = 0; i < 7; i++){
        if(first_idx + 1 <= ava_length[i]) {
            if(ava_length[i]/2 <= first_idx)
            av_l.push_back(ava_length[i]);
        }
    }
    
    // 해당 길이에서 가운데에 1이 있는가
    for(int l : av_l){
        if(bin[(l-1)/2] == 1){
            vector<int> sub_bin(bin.begin(), bin.begin() + l); 
            last_check(sub_bin, 0, (l-1), 1);
            if(flag == true){
                avail = 1; break;
            }
        }
    }
    
    return avail; // 가능 1 불가 0
}

vector<int> solution(vector<long long> numbers) { // 2^50 = 10^15
    vector<int> answer;
    
    make_multi(); // 2의 거듭제곱으로 되어있는 배열 만들기
    make_length();
    
    for(int i = 0; i < numbers.size(); i++){ // 10,000
        int res = check(numbers[i]);
        answer.push_back(res);
    }
    
    return answer;
}