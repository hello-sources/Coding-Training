/*************************************************************************
	> File Name: OJ501传教士.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Fri 31 Jul 2020 06:10:33 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

/*利用搜索找到的数学规律 
1  2  3  4   5   6   7
2  2  4  4   6   6   8
3  4  4  6   7   8   9
4  4  6  6   8   8   10
5  6  7  8   8   10  11
6  6  8  8   10  10  12
7  8  9  10  11  12  12 
*/ 

int main() {
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 1 << endl;
	} else if (n == m) {//对角线上位置 
		cout << n * 2 - 2 << endl;
	} else {
		if (n < m) {//由于是对称的只求一边就行了 
			swap(n, m);
		}
		if (n % 2 == 0) {//对于偶数行 
			cout << (n + m - 1) / 2 * 2 << endl;
		} else {//奇数行 
			cout << n + m - 1 << endl;
		}
	}
	return 0;
}
