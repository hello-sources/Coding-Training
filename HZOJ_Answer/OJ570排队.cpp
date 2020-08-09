/*************************************************************************
	> File Name: OJ570排队.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 09 Aug 2020 08:21:20 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

struct node {
	int num, cnt;	
};
int n, num[80005], ans[80005], all; 

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	stack<node> sta;
	sta.push({210000000, -1});
	for (int i = n - 1; i >= 0; i--) {
		while (sta.top().num < num[i]) {
			node temp = sta.top();
			sta.pop();
			ans[i]++;
			ans[i] += ans[temp.cnt];
		}
		all += ans[i];
		sta.push({num[i], i});
	}
	cout << all << endl;
	return 0;
} 
