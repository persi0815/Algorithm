#include <iostream>
#define endl '\n'
using namespace std;

/*

*/

int t;

void print(int a, int b) {
	if (a == 6 && b == 5) {
		cout << "Sheesh Beesh" << endl;
		return;
	}

	int arr[2] = { a, b };
	for (int i = 0; i < 2; i++) {
		if (arr[i] == 1) {
			cout << "Yakk" << " ";
		}
		else if (arr[i] == 2) {
			cout << "Doh" << " ";
		}
		else if (arr[i] == 3) {
			cout << "Seh" << " ";
		}
		else if (arr[i] == 4) {
			cout << "Ghar" << " ";
		}
		else if (arr[i] == 5) {
			cout << "Bang" << " ";
		}
		else if (arr[i] == 6) {
			cout << "Sheesh" << " ";
		}
	}
	cout << endl;
}

void print_s(int a) {
	if (a == 1) {
		cout << "Habb Yakk" << endl;
	}
	else if (a == 2) {
		cout << "Dobara" << endl;
	}
	else if (a == 3) {
		cout << "Dousa" << endl;
	}
	else if (a == 4) {
		cout << "Dorgy" << endl;
	}
	else if (a == 5) {
		cout << "Dabash" << endl;
	}
	else {
		cout << "Dosh" << endl;
	}
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		cout << "Case " << i+1 << ": ";

		if(a > b) {
			print(a, b);
		}
		else if (a == b) {
			print_s(a);
		}
		else if(a < b){
			print(b, a);
		}
		
	}


}