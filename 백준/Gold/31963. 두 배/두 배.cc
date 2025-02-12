#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/* 두배
길이 n인 양의 정수열을 오름차순으로 만들고자 함.
수열 중 하나의 원소 값을 2배할 수 있음.
해당 연산을 최소 횟수로 적용해서 오름차순으로 만들어야.
값 자체가 아닌 지수를 배열에 저장해야 한다.
원본 배열에 밑이 2인 로그를 취해서 double 타입으로 저장!!
*/

int n;
vector<double> res;  // log2 값을 저장할 배열
long long cnt = 0;

double log_b(double x) {
    return log(x) / log(2);
}

void solution() {
    for (int i = 1; i < n; i++) {
        if (res[i - 1] > res[i] + 1e-9) {  // 부동소수점 오차 보정 추가

            double diff = res[i - 1] - res[i];
            long long needed = (fmod(diff, 1.0) < 1e-9) ? (long long)diff : (long long)ceil(diff);

            cnt += needed;
            res[i] += needed;  // log2 값 증가 (실제 값 *2 효과)
        }
    }
    cout << cnt << endl;
}

int main() {
    cin >> n;
    res.resize(n);  // 크기를 n으로 조정

    for (int i = 0; i < n; i++) {
        long long val;
        cin >> val;
        if (val <= 0) {
            cerr << "Error: 입력값이 양수가 아닙니다." << endl;
            return 1; // 에러 종료
        }
        res[i] = log_b(val);  // log2 값을 저장
    }

    solution();
}
