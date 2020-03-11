#include <iostream>
using namespace std;

char ans[2200][2200];//全局变量默认设置为0 
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729, 2187};

//先打印所有图形，传入左上角坐标，以及对应大小n 
void func(int x, int y, int n) {
	if (n == 1) {
		ans[x][y] = 'X';//定位到边长为1直接输出X 
		return ;
	}
	func(x, y, n - 1);//输出当前图形 
	func(x, y + num[n] / 3 * 2, n - 1);//输出当前图形右边图形 
	func(x + num[n] / 3 * 2, y, n - 1);//输出当前位置下一个图形 
	func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);//输出最右下角图形 
	func(x + num[n] / 3, y + num[n] / 3, n - 1);//输出中心图形 
}

int main() {
	func(1, 1, 7);//对应打印所有图案 
	int n;
	while (cin >> n) {
		if (n == -1) break;//判断是否问结束符号 
		for (int i = 1; i <= num[n]; i++) {
			for (int j = 1; j <= num[n]; j++) {
				//检查当前位置的字符是不是X，如果是就直接输出 
				if (ans[i][j] == 'X') cout << 'X';
				else cout << ' ';
				//否则输出空格 
			}
			cout << endl;//每一次完事之后输出换行符 
		}
		cout << "-" << endl;
	}
	return 0;
}
