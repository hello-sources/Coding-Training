/*************************************************************************
	> File Name: OJ585排名.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 16 Aug 2020 08:45:30 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm> 
using namespace std;

struct node {
	int num, cnt;
};

bool cmp(node a, node b) {
	if (a.num == b.num) {
		return a.cnt < b.cnt;
	}
	return a.num > b.num;
}

int main() {
	int n;
	node s[205];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].num >> s[i].cnt;
	}
	sort(s, s + n, cmp);
	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = 0; j < i; j++) {
			if (s[j].cnt < s[i].cnt) {
				x++;
			}
		}
		cout << x << endl;
	} 
	return 0;
} 
