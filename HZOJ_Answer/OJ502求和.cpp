/*************************************************************************
	> File Name: OJ502求和.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 31 Jul 2020 06:16:43 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath> 
using namespace std;

//利用绝对值来排序，然后遍历求解最小的和 
int n, num[1000005];

bool cmp(int a, int b) {
	return abs(a) < abs(b);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n, cmp);
	int ans = 210000000;
	for (int i = 1; i < n; i++) {
		ans = min(ans, abs(num[i - 1] + num[i]));
	}
	cout << ans << endl;
	return 0;
} 
