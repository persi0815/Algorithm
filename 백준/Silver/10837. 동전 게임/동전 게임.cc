#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k, c;
    cin >> k >> c;

    while (c--) {
        int a, b;
        cin >> a >> b;

        int gap = abs(a - b);
        int remain = k - max(a, b);

        if (a == b) {
            cout << "1\n";
        } else if (a < b) {
            cout << ((gap - remain <= 1) ? "1\n" : "0\n");
        } else {
            cout << ((gap - remain <= 2) ? "1\n" : "0\n");
        }
    }

    return 0;
}
