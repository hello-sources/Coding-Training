#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y, step;
}; 

int dir[12][2] = {1, 2, 1, -2, -1, 2, -1, -2,
				  2, 1, 2, -1, -2, 1, -2, -1,
				  2, 2, 2, -2, -2, 2, -2, -2};
int x1, y1, x2, y2, check1[505][505], check2[505][505]; 

int main() {
	queue<node> que;
	cin >> x1 >> y1 >> x2 >> y2;
	que.push({x1, y1, 0});
	check1[x1][y1] = 1;
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		if (temp.x == 1 && temp.y ==1) {
			cout << temp.step << endl;
			break;
		}
		for (int i = 0; i < 12; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (x < 1 || y < 1 || x > 500 || y > 500) continue;
			if (check1[x][y] == 0) {
				que.push({x, y, temp.step + 1});
				check1[x][y] = 1;
			}
		}
	}
	while (!que.empty()) {
		que.pop();
	}
	que.push({x2, y2, 0});
	check2[x2][y2] = 1;
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		if (temp.x == 1 && temp.y ==1) {
			cout << temp.step << endl;
			break;
		}
		for (int i = 0; i < 12; i++) {
			int x = temp.x + dir[i][0];
			int y = temp.y + dir[i][1];
			if (x < 1 || y < 1 || x > 500 || y > 500) continue;
			if (check2[x][y] == 0) {
				que.push({x, y, temp.step + 1});
				check2[x][y] = 1;
			}
		}
	}
	return 0;
}
