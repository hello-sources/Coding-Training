/*************************************************************************
	> File Name: OJ395复制书稿.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Mon 20 Jul 2020 08:08:12 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//二分答案分的就是消耗的时间 
//根据需求分解，人数大于k就增大时间，否则应该减小 
//000000011111问题 
int k, m, num[505], ans[505][2], l, r; 
//答案数组一个人抄书两个数 

int check(int mid) {
	int sum = 0, s = 0;//sum表示抄到多少了，s表示需要几个人 
	for (int i = 0; i < m; i++) {
		if (sum + num[i] == mid) {
			sum = 0;//对应清零 
			s++;//换下一个人 
		} else if (sum + num[i] > mid) {
			sum = num[i];//这本书抄不下 
			s++;//换人 
		} else {
			sum += num[i];
		}
	}
	if (sum != 0) {
		s++;//拉了一个人，需要加一 
	} 
	return s;
}

int main() {
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> num[i];
		r += num[i];//人数上限 
	}
	while (l != r) {
		int mid = (l + r) >> 1;
		int s = check(mid);//根据mid求出需要的人数 
		if (s > k) {//000000111111类型的 
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	ans[k][1] = m;//表示最后一本书 
	int now = num[m - 1], j = k;//now表示抄了多少时间 
	for (int i = m - 2; i >= 0; i--) {//从后往前扫描一遍所有的书 
		if (now + num[i] > l) {//现在抄的加上num大于l表示抄不下了 
			ans[j][0] = i + 2;//从1开始的 
			j--;//换人 
			now = num[i];//下一个人开始抄书 
			ans[j][1] = i + 1;//下一个人抄书的最后一页 
		} else if (now + num[i] == 1) {//抄完这一本书就结束 
			ans[j][0] = i + 1;//抄的第一本书更新 
			j--;
			i--;//这一本抄完了 
			now = num[i];//下一个人开始抄写下一本 
			ans[j][1] = i + 1;
		} else {
			now += num[i];//最朴素的情况直接加等于num[i] 
		}
	}
	ans[1][0] = 1; 
	for (int i = 1; i <= k; i++) {
		cout << ans[i][0] << " " << ans[i][1] << endl;
	}
	
	return 0;
} 
