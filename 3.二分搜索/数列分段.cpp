#include <iostream>
using namespace std;

long long n, m, num[100005], mmax, x;

long long check(long long mid) {
	int now = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (now + num[i] == mid) {
			cnt++;
			now = 0;
		} else if (now + num[i] > mid) {
			cnt++;
			now = num[i];
		} else {
			now += num[i];
		}
	}
	if (now > 0) cnt++;
	return cnt;
}

long long func() {
	long long l = x, r = mmax;
	while (l != r) {
		long long mid = (l + r) >> 1;
		long long cnt = check(mid);
		if (cnt > m) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
} 

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		mmax += num[i];
		x = max(num[i], x);
	}
	cout << func() << endl;
	
	
	return 0;
}
