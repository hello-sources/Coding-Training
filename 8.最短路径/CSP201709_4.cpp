/*************************************************************************
    > File Name: CSP201709_4.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 06 Jun 2020 05:13:34 PM CST
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 1e5+5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

int n, m;
vector<int> G[1005];
bool vis[1005];
bool know[1005][1005];
// know[i][j] i -> j

void dfs(int id, int s) {
    vis[id] = true;
//    for (int i = 0; i < G[i].size(); i++) {
//        int v = G[i][j];
//    }
    know[s][id] = know[id][s] = true;
    for (auto v: G[id]) {
        if (vis[v]) continue;
        dfs(v, s);
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            vis[j] = false;
        }
        dfs(i, i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (know[i][j]) cnt++;
        }
        if (cnt == n) {
            ans++;
        }
    }

    printf("%d\n", ans);

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
