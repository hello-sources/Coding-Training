#include <iostream> 
using namespace std;
//�������飬��ͼ��ô�������1 1��ʼ�Ͳ����б߽��ж� 
int n, m, sx, sy;
char mmap[505][505]; 
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

//�л��ݣ�һ��ѭ����ʾһ�����򣬶��ѭ����ʾ���ѭ�� 
int func(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		//�����ʾ������ֱ�ӷ���1 
		if (mmap[tx][ty] == 'g') return 1;
		if (mmap[tx][ty] == '.') {//�����.��ʾ������ 
			//���Ϊһ������.���ַ�����ʾ�߹��˱����ظ��� 
			mmap[tx][ty] = '*';
			if (func(tx, ty)) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
			//�ҳ����λ�ø�ֵ��x, y 
			if (mmap[i][j] == 's') {
				sx = i;
				sy = j;
			}
		}
	}
	if (func(sx, sy)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return  0;
}
