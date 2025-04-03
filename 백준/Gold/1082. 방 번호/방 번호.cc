#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
/*
방번호를 정할 수 있음. 1층 문방구에서 파는 숫자를 구매해야 함. 
준비한 금액은 M원
숫자는 0 ~ N-1까지 판매. 각 숫자 i의 가격은 Pi
같은 숫자 여러개 구매 가능. 매우 많은 재고 보유중. 원하는 만큼 숫자 구매 가능
최대 m원을 사용해서 만들 수 있는 가장 큰 방 번호는? 

일단, 최대한 자릿수가 높아야 함. 그 다음, 숫자 크기가 커야 함. 
각 숫자를 만들기 위한 최소 비용 구하기..? 
*/

int n, m;
string result_num = "";

int main(){
    cin >> n; 
    
    vector<int> num(n);
    int cheap = -1; int cheap_p = 51;
    for(int i = 0; i <= n-1; i++){
        cin >> num[i]; // 0부터 n-1까지. 0부터 9까지 가능. 
    }
    for(int i = n-1; i >= 0; i--){
        if(cheap_p > num[i]) {
            cheap = i; cheap_p = num[i];
        }
    }
    cin >> m; // 가지고 있는 금액

    
    // 구매한 방번호들 개수
    vector<int> purchase(n, 0);
    
    // 일단 0이 아닌 가장 싼 걸로 다 사. 
    int cnt = m/cheap_p; 
    purchase[cheap] += cnt;

    int left_p = m % cheap_p;
    int now = n-1;
    // 나머지가 없었는데, 0으로만 사는 경우..!
    int flag = 0;
    if(cheap == 0){
        flag = -1;
        while(purchase[cheap] > 0 && flag == -1){
            left_p += cheap_p; 
            purchase[cheap]--; // 계속 뺐는데도 안됐어 그러면 끝.
            for(int i = n-1; i > 0; i--){
                if(left_p >= num[i]){
                    left_p -= num[i]; purchase[i]++;
                    flag = 1; break;
                }
            }
        }
    }

    // for(int p : purchase){
    //     cout << p << " ";
    // }
    // cout << endl;
    
    // 그 다음에 돈이 남으면 숫자 크고 비싼거랑 바꿔치기 해. 
    // 큰 수부터? 어짜피 큰게 최대한 많아야 좋은 것..! 
    // 수가 적더라도 최대한 높은 자릿수에 큰 숫자가 들어가면 좋음
    
    while(flag != -1 && left_p >= 0 && cheap < now){ // 새로 사는게 더 커야 해
        if(num[now] <= left_p + cheap_p && purchase[cheap] > 0){ // 기존꺼 버리고 새거 살 수 있어
            //cout << "lef1 " << now << " " << left_p << " " << cheap_p << " " << num[now] << endl; 
            left_p = left_p + cheap_p - num[now]; 
            //cout << "lef2 " << now << " " << left_p << endl;
            purchase[cheap]--;
            purchase[now]++;
        }
        else {
            now--;
            if(now < 0) break;
        }
    }
    

    // for(int p : purchase){
    //     cout << p << " ";
    // }
    // cout << endl;

    // 큰수부터 사용해서 수 만들어
    for(int i = n-1; i >= 0; i--){
        while(purchase[i]--){
            //cout << i << endl;
            result_num += to_string(i);
            //cout << result_num << endl;
        }
    }
    if(result_num == "") result_num = "0";

    cout << result_num;
    
}