#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

//输入球的位置坐标，开始数组，终点数组 
int t, n, h, r, qiu[1005][3], low[1005], low_num, up[1005], arr[1005][1005], check[1005];

int func(int now) {
	if (up[now] == 1) return 1;//如果对应顶部的值是1表明找到了出口 
	for (int i = 1; i <= n; i++) {//不是终点，就遍历与他联通且未被遍历的点 
		if (arr[now][i] && check[i] == 0) {
			check[i] = 1;//标记数组定义为1， 
			if (func(i)) return 1;//继续遍历 
		}
	}
	return 0;
}

int main() {
	cin >> t;
	while (t--) {//t组数据输入，清零 
		memset(low, 0, sizeof(low));
		memset(up, 0, sizeof(up));
		memset(arr, 0, sizeof(arr));
		memset(check, 0, sizeof(check));
		low_num = 0;
		cin >> n >> h >> r;
		for (int i = 1; i <= n; i++) {
			cin >> qiu[i][0] >> qiu[i][1] >> qiu[i][2];//输入球的坐标 
			if (qiu[i][2] <= r) {//球心小于半径，表明是起点 
				low[low_num] = i;
				low_num++;
			}
			if (qiu[i][2] + r >= h) {//判断终点，高于h就是相割 
				up[i] = 1;
			}
			//处理边的问题，判断边是否联通 
			for (int j = 1; j < i; j++) {
				int t0 = qiu[i][0] - qiu[j][0];//x
				int t1 = qiu[i][1] - qiu[j][1];//y 
				int t2 = qiu[i][2] - qiu[j][2];//z
				if (sqrt(t0 *t0 + t1 * t1 + t2 * t2) <= 2 * r) {
					arr[i][j] = arr[j][i] = 1;//边联通，邻接矩阵对应数就置为1 
				}
			}
		}
		//遍历起点数组，判断是否找到，成功返回一，输出Yes 
		int flag = 0;
		for (int i = 0; i <= low_num; i++) {
			if (check[i] == 0) {
				check[i] = 1;
				if (func(i)) {
					cout << "Yes" << endl;
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) {
			cout << "No" << endl;
		}
	}
	return 0;
} 
