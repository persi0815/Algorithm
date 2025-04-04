#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    // 문자열을 뒤집어서 일의 자리부터 접근
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int idx = 0, carry = 0;
    string res = "";

    while (idx < str1.size() || idx < str2.size() || carry > 0) {
        int bit1 = (idx < str1.size()) ? str1[idx] - '0' : 0;
        int bit2 = (idx < str2.size()) ? str2[idx] - '0' : 0;
        int sum = bit1 + bit2 + carry;

        res += (sum % 2) + '0'; // 0 또는 1을 문자로 추가
        carry = sum / 2;

        idx++;
    }

    // 결과 뒤집기
    reverse(res.begin(), res.end());

    // 앞자리 0 제거
    int first_non_zero = res.find_first_not_of('0');
    if (first_non_zero == string::npos) {
        cout << "0"; // 모두 0이면 그냥 "0"
    } else {
        cout << res.substr(first_non_zero);
    }

    return 0;
}
