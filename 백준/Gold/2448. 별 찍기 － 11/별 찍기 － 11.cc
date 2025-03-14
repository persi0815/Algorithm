#include <iostream> 
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
//char arr[3*pow(2, 10)][2 * (3*pow(2, 10))];
char arr[3 * (1 << 10)][2 * (3 * (1 << 10))];


void print(int row, int col, int size){
    if(size == 3){ // top부터 별 1, 2, 5찍기
        arr[row][col] = '*';  // 최상단 별
        arr[row + 1][col - 1] = '*'; arr[row + 1][col + 1] = '*'; // 2번째 줄
        arr[row + 2][col - 2] = '*'; arr[row + 2][col - 1] = '*'; 
        arr[row + 2][col] = '*'; 
        arr[row + 2][col + 1] = '*'; arr[row + 2][col + 2] = '*'; // 3번째 줄
        return;
    }
    
    int new_size = size/2;
    print(row , col, new_size);
    print(row + new_size, col - new_size, new_size);
    print(row + new_size, col + new_size, new_size);
}

int main(){
    cin >> n;
    memset(arr, ' ', sizeof(arr));
    //for - fill(arr[i], arr[i] + 2 * (3 * (1 << 10)), ' ');
    
    
    print(0, n-1, n); 
    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*n-1; j++){
            cout << arr[i][j] ;
        }
        cout << endl;
    }
}


