/*************************************************************************
	> File Name: OJ255安装雷达.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 22 Aug 2020 08:53:48 AM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX_N 1000

struct Range {
	double x, y;
} arr[MAX_N + 5], point[MAX_N + 5];
int n;
double d;

bool cmp(const Range &a, const Range &b) {
	if (a.y != b.y) return a.y < b.y;
	return a.x > b.x;
}

int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> point[i].x >> point[i].y;
		double c = sqrt(d * d - point[i].y * point[i].y);
		if (point[i].y > d) {
			cout <<  -1 << endl;
			return 0;
		}
		arr[i].x = point[i].x - c;
		arr[i].y = point[i].x + c;
	}
	sort(arr, arr + n, cmp);
	double p = arr[0].y;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i].x <= p) continue;
		p = arr[i].y;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
