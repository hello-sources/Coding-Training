/*************************************************************************
    > File Name: 独木舟.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 13 May 2020 06:19:35 PM CST
 ************************************************************************/


#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 30000

int w, n, a[MAX_N + 5], ans;

int main() {
	cin >> w >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int i = 1, j = n ;
	while (i <= j) {
		if (a[i] + a[j] <= w) {
			i++;
		}
		j--;
		ans++;
	}
	cout << ans << endl;
	return 0;
} 
