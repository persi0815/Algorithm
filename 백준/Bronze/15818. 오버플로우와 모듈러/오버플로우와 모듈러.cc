#include <iostream>
using namespace std;
typedef long long ll;

int N; ll M;
ll ans = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	while (N--) {
		ll x; cin >> x;
		ans = (ans * x) % M;
	}

	cout << ans;
}