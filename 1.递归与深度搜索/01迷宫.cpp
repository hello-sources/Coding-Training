#include <iostream>
#include <queue>
using namespace std;
//��¼�ڵ�λ�� 
struct node {
	int x, y;
};

int n, m, k, ans;
char mmap[3005][3005];
int check[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}; 
queue<node> que;//��ʼ��һ������ 

void func(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		//���������ж��Ƿ���Խ���Լ���Ӧ�ı��Ԫ���Ƿ�Ϊ0 
		if (check[tx][ty] == 0 && mmap[tx][ty] != mmap[x][y] && mmap[tx][ty]) {
			ans++;//���´� 
			check[tx][ty] = 1;//���λ��Ϊ1 
			que.push({tx, ty});//λ����� 
			func(tx, ty);//�ݹ���� 
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> (&mmap[i][1]);//�����ַ���ά����һ��ѭ�����뷽�� 
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check[i][j] == 0) {// �����������룬���û��ʹ�� 
				ans = 1;//�𰸴�1��ʼ 
				check[i][j] = 1;//���������Ϊ1 
				que.push({i, j});//��Ӧ��λ�ý������ 
				func(i, j);//�ݹ������� 
				while (!que.empty()) {//���зǿյ�ʱ��˵���õ��Ѿ�������� 
					node temp = que.front();
					que.pop();//��������Ԫ�س�ջ 
					check[temp.x][temp.y] = ans;//��Ӧ���λ�������ֵΪ��Ӧ�Ĵ� 
				}
			}
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b;//������Ӧ����Ԫ�� 
		cin >> a >> b;
		cout << check[a][b] << endl;//�����¼����Ӧ��Ԫ�� 
	}
	return 0;
}
