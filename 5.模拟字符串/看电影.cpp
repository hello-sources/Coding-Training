#include <iostream> 
using namespace std;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int main() {
	int N, K, Id;
	cin >> N >> K >> Id;
	if (N == K) cout << "1/1";
	else if (K == 0) cout << "0/1";
	else {
		int t = gcd(N, K);
		cout << K / t << "/" << N / t;
	}
	cout << endl;
	return 0;
}
