/*************************************************************************
	> File Name: OJ261数据结构.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 25 Aug 2020 04:55:53 PM CST
 ************************************************************************/

#include <iostream>
#include <stack> 
using namespace std;
#define MAX_N 1000
long long sum[MAX_N + 5];
long long f[MAX_N + 5];

int main() { 
	long long n;
	f[0] = 0x8000000000000000;
	stack<long long> s1, s2;
	char op[10];
	cin >> n;
	while (n--) {
		cin >> op;
		switch (op[0]) {
			case 'I': {
				long long x;
				cin >> x;
				s1.push(x);
				long long ind = s1.size();
				sum[ind] = sum[ind - 1] + x;
				f[ind] = max(f[ind - 1], sum[ind]);
				break;
			}
			case 'D': {
				if (!s1.empty()) s1.pop();
				break;
			}
			case 'L': {
				if (s1.empty()) break;
				s2.push(s1.top());
				s1.pop(); 
				break;
			}
			case 'R': {
				if (s2.empty()) break;
				s1.push(s2.top());
				long long ind = s1.size();
				sum[ind] = sum[ind - 1] + s2.top();
				f[ind] = max(f[ind - 1], sum[ind]);
				s2.pop();
				break;
			}
			case 'Q': {
				long long k;
				cin >> k;
				cout << f[k] << endl;
				break;
			}
		}
	}	
	return 0;
} 
