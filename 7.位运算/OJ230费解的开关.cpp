/*************************************************************************
	> File Name: OJ230费解的开关.cpp
	> Author: ltw
	> Mail: 3245849061@qq.com
	> Github: https://github.com/hello-sources
	> Created Time: Tue 07 Jul 2020 10:34:37 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

//二进制数组存储进来 
int num[5][5] = {
	1, 2, 4, 8, 16,
	32, 64, 128, 256, 512,
	1024, 2048, 4096, 8192, 16384,
	32768, 65536, 131072, 262144, 524288,
	1048576, 2097152, 4194304, 8388608, 16777216
};
//方向数组，自身也算一个方向 
int dir[5][2] = {0, 1, 1, 0, 0, -1, -1, 0, 0, 0};

int make(int x, int xx, int yy) {
	for (int i = 0; i < 5; i++) {
		int xxx = xx + dir[i][0];
		int yyy = yy + dir[i][1];
		if (xxx < 0 || yyy < 0 || xxx > 4 || yyy > 4) {
			continue;
		}
		if (x & num[xxx][yyy]) {
			x -= num[xxx][yyy];
		} else {
			x += num[xxx][yyy];
		}
	}
	return x;
}

int doit(int x) {
	int ans = 0;//表示按了几次 
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if ((x & num[i][j]) == 0) {
				x = make(x, i + 1, j);//点下一个点 
				ans++;//次加一数 
			}
		}
	}
	//如果全是1的情况 
	if (x != 33554431) return 9999;
	else return ans;
}

//状态，位置，次数 
int func5(int x, int s, int step) {
	if (s == 5) {//递归边界条件 
		return doit(x) + step; //表示x状态表示需要的步数加上第一排步数 
	}
	int ans = 9999;
	ans = min(ans, func5(x, s + 1, step));//不点这个按钮 
	x = make(x, 0, s);//点的话，改变x的状态，(状态，坐标，次数) 
	ans = min(ans, func5(x, s + 1, step + 1));//点这个按钮 
	return ans;
}

//主要目的处理输入 
void func() {
	int x = 0, ans = 9999;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			char t;
			cin >> t;
			if (t == '1') {
				x += num[i][j];//循环读入字符，如果等于1就加上对应的数 
			}
		}
	}
	//第一个参数表示状态，第几个按钮点不点，第三个参数是点了多少次 
	ans = min(ans, func5(x, 0, 0));//枚举递归状态 
	if (ans == 9999) cout << -1 << endl;//不可达输出-1 
	else cout << ans << endl;//否则输出答案 
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		func();
	}	
	
	return 0;
} 
