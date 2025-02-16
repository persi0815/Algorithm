#include <iostream>
using namespace std;

int x, y;
int day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	cin >> x >> y;

	int total = 0;
	for (int i = 0; i < x; i++) {
		total += day[i];
	}
	total += y;

	int d = (total-1) % 7;
	//cout << total << " " << d << endl;

	if (d == 1) cout << "TUE";
	else if (d == 2) cout << "WED";
	else if (d == 3) cout << "THU";
	else if (d == 4) cout << "FRI";
	else if (d == 5) cout << "SAT";
	else if (d == 6) cout << "SUN";
	else if (d == 0)cout << "MON";

}