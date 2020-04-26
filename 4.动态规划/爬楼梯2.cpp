#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int f[4] = {1, 0, 1, 1};
	if (n < 4) {
		cout << f[n] << endl;
		return 0;
	}
	for (int i = 4; i <= n; i++) {
		f[i % 4] = f[(i - 2) % 4] + f[(i - 3) % 4];
	}
	cout << f[n % 4] << endl;
	return 0;
} 
