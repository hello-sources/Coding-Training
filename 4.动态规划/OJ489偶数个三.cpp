/*************************************************************************
	> File Name: OJ489偶数个三.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Thu 30 Jul 2020 12:45:01 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//递推公式J[n] = O[n - 1] + 9 * J[n - 1]
//O[n] = J[n - 1] + 9 * O[n - 1] 
//J数组表示奇数个三，O数组表示偶数个三 

int main() {
	int n, ji[1005] = {0, 1}, ou[1005] = {0, 8};
	cin >> n;
	for (int i = 2; i <= n; i++) {
		ji[i] = ji[i - 1] * 9 + ou[i - 1];
		ou[i] = ji[i - 1] + 9 * ou[i - 1];
		ji[i] %= 12345;
		ou[i] %= 12345; 
	} 
	cout << ou[n] << endl;
	return 0;
}
