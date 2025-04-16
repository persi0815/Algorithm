#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int cnt = 0;

    while (n >= 3) {
        if (n % 5 == 0) {
            cnt += n / 5;
            n = 0;
        } else {
            n -= 3;
            cnt += 1;
        }
    }

    if (n == 0) {
        std::cout << cnt << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}
