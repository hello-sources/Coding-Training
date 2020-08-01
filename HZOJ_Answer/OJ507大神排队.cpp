/************************************************************************* > File Name: OJ507大神排队.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 01 Aug 2020 08:48:04 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int a, b;
};

bool cmp(node x, node y) {
	if (x.a + x.b == y.a + y.b) return x.a < y.a;
	return x.a + x.b < y.a + y.b;
}

int main() {
	int n;
	node stu[50005];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].a >> stu[i].b; 
	}
	sort(stu, stu + n, cmp);
	int ans = -999999999, sum = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, sum - stu[i].b);
		sum += stu[i].a;
	}
	cout << ans << endl;
	return 0;
} 
