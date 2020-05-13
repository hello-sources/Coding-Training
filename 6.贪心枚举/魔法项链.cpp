/*************************************************************************
    > File Name: 魔法项链.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Wed 13 May 2020 08:48:01 PM CST
 ************************************************************************/



#include <iostream>
using namespace std;

int n, m, ans[30005], mem[30005];
char str[30005]; 

int main() {
	cin >> n >> m >> &str[1];
	//枚举长度 
	for (int i = 1; i <= n / 2; i++) {
		int same = 0;
		//计算魔力值 
		for (int j = 1, k = i + 1; j <= i; j++, k++) {
			if (str[j] == str[k]) {
				same++;
			} 
		}
		ans[same]++;//魔力值计入ans数组相应位置中去， 
		for (int j = 2; j + 2 * i - 1 <= n; j++) {
			if (str[j - 1] == str[j - 1 + i]) {
				same--;//如果最左边的不想等就减去一 
			}
			if (str[j + i - 1] == str[j + 2 * i - 1]) {
				same++;//如果第二个的最右边相等就加上一 
			}
			ans[same]++;
		} //类似于滑动窗口法，就是相同的地方不再进行计算 
		mem[i] = same;//记忆化当前字串匹配度多少 
	}
	//m次操作 
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 2) {
			cin >> t;
			cout << ans[t] << endl;//如果是2直接输出魔力值即可 
			continue;
		} 
		char l;
		cin >> l;//如果是1，就在字符串后面再加上一个字符 
		str[++n] = l;
		if (n % 2 == 0) {//若加入后长度为偶数，则计算新长度字串 
			int same = 0, mid = n >> 1;
			for (int j = 1, k = 1 + mid; j <= mid; j++, k++) {
				//貌似就是把该序列从中间劈开，然后比较两个字串相似度 
				if (str[j] == str[k]) {
					same++;
				}
			}
			ans[same]++;
			mem[mid] = same;
		}
		//与上面类似是为了避免重复计算使用类似于滑动窗口法则 
		//将之前所有长度最后状态取出，向后移动 
		for (int j = 1; j <= (n - 1) >> 1; j++) {
			if (str[n - j - j] == str[n - j]) {
				mem[j]--;
			}
			if (str[n] == str[n - j]) {
				mem[j]++;
			}
			ans[mem[j]]++;
		}
	}
	return 0;
}
