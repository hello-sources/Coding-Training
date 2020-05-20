/*************************************************************************
    > File Name: 奶牛碑文.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 20 May 2020 08:43:32 PM CST
 ************************************************************************/

#include <iostream>
#include <string> 
using namespace std;

string str;
long long n, ans, numc[100005], numw[100005], nc, nw;

int main() {
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'C') nc++;
		numc[i] = nc;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (str[i] == 'W') nw++;
		numw[i] = nw;
	}
	for (int i = 0; i < n; i++) {
		if (str[i] == 'O') {
			ans += numc[i] * numw[i];
		}
	}
	cout << ans << endl;
	
	return 0;
}
