/*************************************************************************
	> File Name: OJ512分砖块.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 18 Oct 2020 06:43:32 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000
int cnt[MAX_N + 5], t[MAX_N + 5];

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {
	int n, c[2] = {0};	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cnt[i] >> t[i];
		c[t[i]] += cnt[i];
	}
	if (c[0] == 0 || c[1] == 0) {
		cout << c[0] + c[1] << endl;
		return 0;
	}
	do {
		int r = gcd(c[0], c[1]);
		c[0] /= r;
		c[1] /= r; 
	} while (0);
	int x[2] = {0}, ans = 0;
	cout << " 0 / 1 : " << c[0] << " " << c[1] << endl; 
	for (int i = 1; i <= n; i++) {
		if ((x[0] == 0 && x[1] == 0) || x[!t[i]] % c[!t[i]]) {
			x[t[i]] += cnt[i];
			continue;
		}
		int r = x[!t[i]] * c[t[i]] / c[!t[i]] - x[t[i]];
		cout << x[0] << " " << x[1] << " " << r << endl;
		if (r < 0 || r > cnt[i]) {
			x[t[i]] += cnt[i];
		} else {
			ans += 1;
			x[0] = x[1] = 0;
			x[t[i]] = cnt[i] - r;
		}
	}
	cout << ans << endl;
	return 0;
} 
