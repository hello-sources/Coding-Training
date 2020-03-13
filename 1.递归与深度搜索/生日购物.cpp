#include <iostream>
#include <algorithm>
using namespace std;

int n, x, num[45], set[2][3000005], cnt[2];

void func(int s_no, int s, int e, int sum) {
	if (sum > x) return ;
//	int flag = 0;
	for (int i = s; i < e; i++) {
		sum += num[i];
		set[s_no][cnt[s_no]] = sum;//右半部分数和小于x的情况 
		cnt[s_no]++;//统计右半部分有多少情况小于x 
		func(s_no, i + 1, e, sum);//递归搜索 
		sum -= num[i];//回溯 
	}
//	return flag;
} 

int main() {
	while (cin >> n >> x) {
		cnt[0] = cnt[1] = 1;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		func(0, 0, n / 2, 0);//递归搜索左半部分 
		func(1, n / 2, n, 0);//递归搜索右半部分 
		sort(set[1], set[1] + cnt[1]);
		//只是需要对于右半部分的数进行排序操作 
		int flag = 0;//标志位引入
		//二分查找，从左边数组找出一个数，从右边数组找到是否存在两数之和等于x这种情况 
		for (int i = 0; i < cnt[0]; i++) {
			int target = x - set[0][i];
			int l = 0, r = cnt[1] - 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (set[1][mid] == target) {
					cout << "YES" << endl;//找到了直接跳出循环 
					flag = 1;//对应标志位记作1 
					break;
				} else if (set[1][mid] < target) {
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			if (flag) break;
		}
		!flag && cout << "NO" << endl;
//		if (func(0, 0)) cout << "YES" << endl;
//		else cout << "NO" << endl;
	}	
	return 0;
}
