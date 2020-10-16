/*************************************************************************
	> File Name: OJ510飞行员配对.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sat 17 Oct 2020 06:43:08 AM CST
 ************************************************************************/

#include <iostream>
#include <set>
using namespace std;
#define MAX_N 10000
int x[MAX_N + 5], y[MAX_N + 5];

typedef pair<int, int> PII; 

int main() {
	int n;
	set<PII> s; 
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	int ans = y[1] + x[2];
	s.insert(PII(y[2] - x[2], 2));
	for (int i = 4; i <= n; i += 2) {
		int val1 = ans + x[i] + y[i - 1];
		int val2 = ans + x[i] + x[i - 1] + s.begin()->first;
		ans = min(val1, val2);
		if (val1 < val2) {
			s.insert(PII(y[i] - x[i], i));
		} else {
			s.erase(s.begin());
			s.insert(PII(y[i] - x[i], i));
			s.insert(PII(y[i - 1] - x[i - 1], i - 1));
		}
	}
	cout << ans << endl;
	return 0;
} 
