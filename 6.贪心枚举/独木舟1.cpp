/*************************************************************************
    > File Name: 独木舟1.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 13 May 2020 06:24:03 PM CST
 ************************************************************************/


#include <iostream>
#include <algorithm>
using namespace std;

int w, num[30005], ans, n;

int main() {
	cin >> w >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	for (int i = n - 1; i >= 0; i--) {
		if (num[i] == 0) continue;
		for (int j = i - 1; j >= 0; j--) {
			if (num[j] && num[i] + num[j] <= w) {
				num[j] = 0;
				break;
			}
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}
