#include <iostream>
using namespace std;

int N, a, b, c; 

int main() {
	cin >> N >> a >> b >> c;
	if (a < b && b < c) cout << 1 << endl;
	else if (b < c && c > a) {
		cout << 0 << endl;
	} else if (a > b && c > b) {
		cout << 1 << endl;
	} else if (a < b && a > c) {
		cout << 1 << endl;
	} else cout << 0 << endl;
	return 0;
} 
