/*************************************************************************
	> File Name: OJ526旅行家问题.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Sun 02 Aug 2020 05:52:22 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//加油站节点，分别表示离起点距离以及油价 
struct node {
	double d, p;
};

//比较函数，根据距离来排序 
bool cmp(node a, node b) {
	return a.d < b.d;
}

double d1, c, d2, p1, ans;
int n;
node oil[10];//加油站 

//递归函数，参数是第几个加油站，还有多少油 
int func(int onum, double lnum) {
	double dis = c * d2;//表示能走多远，邮箱容量乘以d2 
	int ind = 9;//标志 
	for (int i = onum + 1; i <= n + 1 && oil[i].d - oil[onum].d <= dis; i++) {
		if (oil[i].p < oil[ind].p) {//遍历所有加油站，找到最便宜还能到的加油站 
			ind = i;
		}
	}
	if (ind == 9) return 0; //如果还是等于9，表示任意一个加油站都去不了 
	if (oil[ind].p > oil[onum].p) {//要去的油价贵的情况 
		if (oil[onum].d + dis >= d1) {//能直接到终点直接去终点 
			ans += ((d1 - oil[onum].d) / d2 - lnum) * oil[onum].p;//计算费用 
			return 1;
		} else {
			ans += (c - lnum) * oil[onum].p;//不能直接到终点，就把油加满，去下一个加油站 
			return func(ind, c - (oil[ind].d - oil[onum].d) / d2);//去下一个加油站 
		} 
	} else {
		ans += (((oil[ind].d - oil[onum].d) / d2) - lnum) * oil[onum].p;//下一个加油站便宜的情况下直接去就行了 
		return func(ind, 0);//递归到下一个加油站，正好邮箱的油用完 
	}
}

int main() {
	cin >> d1 >> c >> d2 >> p1 >> n;
	oil[0].d = 0;//起点初始化 
	oil[0].p = p1;
	oil[n + 1].d = d1;//终点作为加油站 
	oil[n + 1].p = 2100000000;//终点加油站油价没用 
	oil[9].p = 21000000001;//设置一个虚拟节点 
	for (int i = 1; i <= n; i++) {
		cin >> oil[i].d >> oil[i].p;
	} 
	sort(oil + 1, oil + n + 1, cmp);
	if (func(0, 0) == 1) {//递归函数 
		printf("%.2f\n", ans);
	} else {
		printf("No Solution");
	}
	return 0;
} 
