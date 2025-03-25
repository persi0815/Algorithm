#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int d = y - x;

        int k = (int)sqrt(d);
        if (k * k == d) {
            cout << 2 * k - 1 << '\n';
        } else if (k * k < d && d <= k * k + k) {
            cout << 2 * k << '\n';
        } else {
            cout << 2 * k + 1 << '\n';
        }
    }
    return 0;
}
