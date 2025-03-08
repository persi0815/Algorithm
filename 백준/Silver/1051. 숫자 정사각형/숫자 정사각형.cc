#include <string>
#include <iostream> 
#include <vector> 
using namespace std;

int main(){
    // 입력
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        for(int j = 0; j < m; j++){
            arr[i][j] = str[j]-'0';
        }
    }
    
    int res = 1;
    for(int next_size = 1; next_size <= 50; next_size++){
        bool flag = false;
        
        for(int r = 0; r < n-next_size; r++){
            for(int c = 0; c < m-next_size; c++){
                // 해당 지점에서 우, 대각, 아래 점검
                int num = arr[r][c];
                if(num == arr[r][c+next_size] 
                   && num == arr[r+next_size][c+next_size]
                  && num == arr[r+next_size][c]){
                    flag = true;
                    res = next_size+1;
                }
                if(flag) break;
            }
            if(flag) break;
        }
        
    }
    
    cout << (res)*(res);
    
}
