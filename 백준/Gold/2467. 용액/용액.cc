#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> liquids(n);
    for (int i = 0; i < n; ++i) {
        cin >> liquids[i];
    }

    int left_idx = 0;
    int right_idx = n - 1;

    int ans = abs(liquids[left_idx] + liquids[right_idx]);
    int ans_left = left_idx;
    int ans_right = right_idx;

    while (left_idx < right_idx) { // left_idx와 right_idx는 만나면 안된다
        int tmp = liquids[left_idx] + liquids[right_idx];

        if (abs(tmp) < ans) {
            ans_left = left_idx;
            ans_right = right_idx;
            ans = abs(tmp);

            if (ans == 0) {
                break;
            }
        }

        if (tmp < 0) {
            left_idx++;
        }
        else {
            right_idx--;
        }
    }

    cout << liquids[ans_left] << " " << liquids[ans_right] << endl;

    return 0;
}
