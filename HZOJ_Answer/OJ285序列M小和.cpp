/*************************************************************************
	> File Name: OJ285序列M小和.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 28 Aug 2020 10:31:04 AM CST
 ************************************************************************/

#include <iostream>
#include <set>
using namespace std;
#define inf 0x3f3f3f3f
#define MAX_M 2000
int a[MAX_M + 5];
typedef pair<int, int> PII;
set<PII> s;
int t = 0;

void extract(int m) {
	for (int j = m - 1; j >= 0; j--) {
		a[j] = -(s.begin()->first);
		s.erase(s.begin());
	}
	return ;
}

int main() {
	int n, m, x;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		s.insert(PII(-x, t++));
	}
	for (int i = 1; i < n; i++) {
		extract(m);
		for (int j = 0; j < m; j++) {
			cin >> x;
			for (int k = 0; k < m; k++) {
				int y = x + a[k];
				if (s.size() == m && y >= -(s.begin()->first)) break;
				if (s.size() == m) s.erase(s.begin());
				s.insert(PII(-y, t++));
			}	
		}
	}
	extract(m);
	for (int i = 0; i < m; i++) {
		i && cout << " ";
		cout << a[i];
	}
	cout << endl;
	return 0;
} 
