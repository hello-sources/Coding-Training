/*************************************************************************
	> File Name: OJ258最大子阵和.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 24 Aug 2020 04:35:29 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100
int arr[MAX_N + 5][MAX_N + 5];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			arr[i][j] += arr[i - 1][j];
		}
	}
	int ans = 0x80000000;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int pre = 0, sum = 0, temp = 0x80000000;
			for (int k = 1; k <= n; k++) {
				sum += arr[j][k] - arr[i - 1][k];
				temp = max(temp, sum - pre);
				pre = min(sum, pre);
			}
			ans = max(ans, temp);
		}
	}
	cout << ans << endl;
	return 0;
} 
