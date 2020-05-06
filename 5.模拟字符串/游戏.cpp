#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n % 2 == 0) {
		int mid = n >> 1;
		if (m <= mid) cout << m + 1 << endl;
		else cout << m - 1 << endl;
	} else {
		int mid = (n + 1) >> 1;
		if (m < mid) cout << m + 1 << endl;
		else cout << m - 1 << endl;
	}
	return 0;
}
