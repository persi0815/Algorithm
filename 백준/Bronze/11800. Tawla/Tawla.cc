#include <iostream>
#define endl '\n'
using namespace std;

int t;

// 주사위 숫자 별칭
string names[7] = {"", "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
// 같은 숫자가 나왔을 때의 별칭
string sameNames[7] = {"", "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"};

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int a, b;
        cin >> a >> b;
        cout << "Case " << i << ": ";

        // 예외 처리: "Sheesh Beesh"
        if ((a == 6 && b == 5) || (a == 5 && b == 6)) {
            cout << "Sheesh Beesh" << endl;
            continue;
        }

        // 두 숫자가 같은 경우 -> 특정 이름 출력
        if (a == b) {
            cout << sameNames[a] << endl;
            continue;
        }

        // 항상 큰 숫자가 먼저 오도록 정렬
        if (a < b) swap(a, b);

        // 일반적인 경우
        cout << names[a] << " " << names[b] << endl;
    }

    return 0;
}
