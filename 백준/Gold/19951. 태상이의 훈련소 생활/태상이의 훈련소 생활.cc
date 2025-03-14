#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
/*
연변장의 흙을 옮겨야 함. n개의 칸. 칸마다 높이 가짐. 
조교 m명. 각자 a부터 b번칸까지 높이 k만큼 흙을 덮거나 파내라고 지시
각 조교의 지시를 모아 연변장 각 칸의 최종 높이를 미리 구해 일을 한번에 수행
조교들의 지시를 모두 수행한 뒤 연변장 각 칸의 높이 구하자. 
*/
int n, m; // 연병장 크기, 조교의 수

int main(){
    cin >> n >> m; 
    vector<int> height(n+1);
    height[0] = 0;
    for(int i = 1; i <= n; i++){ // 높이
        cin >> height[i];
    }
    
    vector<int> prefix_sum(n+2, 0);
    for(int i = 0; i < m; i++){
        int a, b, k; cin >> a >> b >> k;
        prefix_sum[a] += k; prefix_sum[b+1] -= k;
    }
    
    for(int i = 2; i <= n+1; i++){
        prefix_sum[i] += prefix_sum[i-1];
    }
    
    for(int i = 1; i <= n; i++){
        cout << height[i] + prefix_sum[i] << " ";
    }
}
