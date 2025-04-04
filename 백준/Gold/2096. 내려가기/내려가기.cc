#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int max_0 = 0, max_1 = 0, max_2 = 0;
    int min_0 = 0, min_1 = 0, min_2 = 0;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int new_max_0 = max(max_0, max_1) + a;
        int new_max_1 = max({max_0, max_1, max_2}) + b;
        int new_max_2 = max(max_1, max_2) + c;

        int new_min_0 = min(min_0, min_1) + a;
        int new_min_1 = min({min_0, min_1, min_2}) + b;
        int new_min_2 = min(min_1, min_2) + c;

        max_0 = new_max_0; max_1 = new_max_1; max_2 = new_max_2;
        min_0 = new_min_0; min_1 = new_min_1; min_2 = new_min_2;
    }

    cout << max({max_0, max_1, max_2}) << " " << min({min_0, min_1, min_2});
}
