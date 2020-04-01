#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, step;
};

int n, m;
char mmap[1005][1005];
int ans[1005][1005];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int main() {
	cin >> n >> m;
	queue<node> que;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
			//��1��ʼ���ҵ������0 
			//���ǲ��ô�1��ʼ�ң�������������������߽����ٶ� 
			if (mmap[i][j] == '1') {
				que.push({i, j, 0});
				ans[i][j] = -1; //ͬʱ�Ѵ�������Ϊ-1�����ں��洦��� 
			}
		}
	}
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			//�ж��Ƿ�Խ�� 
			if (x < 1 || y < 1 || x > n || y > m || ans[x][y]) continue;
			ans[x][y] = temp.step + 1;//��Ӧ������һ�浽�ṹ���� 
			que.push({x, y, ans[x][y]});//��Ӧ��Ԫ����� 
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j != 1) cout << " ";
			if (ans[i][j] == -1) {//�ж��Ƿ�Ϊ-1 �����Ϊ-1�����0 
				cout << 0;
			} else {
				cout << ans[i][j];//����������Ǵ����� 
			}
		}
		cout << endl;
	}
	return 0;
} 
