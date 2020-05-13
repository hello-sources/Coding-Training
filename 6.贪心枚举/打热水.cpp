/*************************************************************************
    > File Name: 打热水.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 13 May 2020 06:29:49 PM CST
 ************************************************************************/


#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct node {
	int num, time;
};

bool cmp(node a, node b) {
	return a.time < b.time;
}

int n;
node s[35];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].time;
		s[i].num = i + 1;
	}
	sort(s, s + n, cmp);
	int ans = 0, now = 0;
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << s[i].num;
		ans += now;
		now += s[i].time;
	}
	printf("\n%.2f\n", (double)ans / n);
	return 0;
}
