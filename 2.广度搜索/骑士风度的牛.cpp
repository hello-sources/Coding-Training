#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, step;
};

int n, m;
char mmap[200][200];
//���������յķ������� 
int dir[8][2] = {1, 2, 1, -2, 2, 1, 2, -1,
					-1, 2, -1, -2, -2, 1, -2, -1};


int main() {
	cin >> m >> n;
	queue<node> que;
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
			//�ж���ʿ��λ��Ȼ����Ӳ��� 
			if (mmap[i][j] == 'K') {
				que.push({i, j, 0});
			}
		}
	} 
	//���зǿյ�ʱ��ѭ�� 
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		for (int i = 0; i < 8; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (x < 1 || y < 1 || x > n || y > m) continue;
			if (mmap[x][y] == 'H') {//�ҵ��յ��ֱ�����������ҷ��� 
				cout << temp.step + 1 << endl;
				return 0;
			}
			//���������ͱ�ʾû�߹�����עΪ0��������� 
			if (mmap[x][y] == '.') {
				mmap[x][y] = 0;
				que.push({x, y, temp.step + 1});
			}
		}
	}	
	return 0;
} 
