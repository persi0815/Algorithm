#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <iostream>
#define endl '\n'
using namespace std;

//백준 9713번 코드
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        int sum = 0;
        for (int j = 1; j <= num; j += 2) {
            sum += j;
        }
        cout << sum << endl;
    }
}