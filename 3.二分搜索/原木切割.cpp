#include <iostream>
#include <algorithm>
using namespace std;

int n, m, num[100005], mmax;

int func(int len) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += num[i] / len; 
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		mmax = max(mmax, num[i]);
	} 
	int l = 0, r = mmax;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		int s = func(mid);
		if (s >= m) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << endl; 
	return 0;
} 
