#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
 
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector<int> sequence(n+1);
 
    vector<int> increase;
    vector<int> DP(n+1);
 
    DP[0] = 1;
    int len = 0;
 
    for(int i = 1;i<=n;i++){
        cin>>sequence[i];
        DP[i] = 1;
        for(int j = 1;j<i;j++){
            if(DP[i]<=DP[j] and sequence[j]<sequence[i]){
                DP[i] = DP[j] + 1;
            }
        }
        len = max(len, DP[i]);
    }
 
    cout<<len<<endl;
    for(int i = n;i>0;i--){
        if(DP[i] == len){
            increase.push_back(sequence[i]);
            len--;
        }
    }
 
    int size = increase.size();
 
    for(int i = increase.size()-1;i>=0;i--){
        cout<<increase[i]<<" ";
    }
 
    return 0;
}