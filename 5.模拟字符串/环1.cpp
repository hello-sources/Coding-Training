#include <iostream>
using namespace std;

int main() {
	int a, b, c, d = 0;
	cin >> a >> a >> b >> c;
	if (a > b) d++;
	if (b > c) d++;
	if (c > a) d++;
	if (d == 2) cout << 0 << endl;
	else cout << 1 << endl;
	return 0;
}
