/*************************************************************************
    > File Name: 两人过河.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 13 May 2020 07:19:49 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, num[1005], ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	for (int i = n - 1; i >= 0; i -= 2) {
		if (i == 0) {
			ans += num[0];
			break;
		}
		if (i == 1) {
			ans += num[1];
			break;
		}
		if (i == 2) {
			ans += num[0] + num[1] + num[2];
			break;
		}
		ans += min(num[1] + num[0] + num[i] + num[1], num[i] + num[0] + num[i - 1] + num[0]);
	}
	cout << ans << endl;	
	return 0;
} 
