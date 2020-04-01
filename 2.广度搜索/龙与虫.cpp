#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};

int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0,
                1, 1, -1, -1, 1, -1, -1, 1};
int n, m;
char mmap[150][150];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    while (1) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (!a) break;
        int check[150][150] = {0}, check2[150][150] = {0};
        check[a][b] = 1;
        for (int i = 0; i < 8; i++) {
            for (int j = 1; 1; j++) {
                int x = a + j * dir[i][0];
                int y = b + j * dir[i][1];
                if (mmap[x][y] != 'O') break;
                check[x][y] = 1;
            }
        }
        queue<node> que;
        que.push({c, d, 0});
        check2[c][d] = 1;
        int ans = -1;
        while (!que.empty()) {
            node temp = que.front();
            que.pop();
            if (check[temp.x][temp.y] == 1) {
                ans = temp.step;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int x = temp.x + dir[i][0];
                int y = temp.y + dir[i][1];
                if (mmap[x][y] == 'O' && check2[x][y] == 0) {
                    check2[x][y] = 1;
                    que.push({x, y, temp.step + 1});
                }
            }
        }
        if (ans == -1) {
            cout << "Impossible!" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
 
