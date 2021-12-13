/**注意，这他娘的是无向图，不是正儿八经的矩阵
 * 继续借用染色思想，就是随便找一个点染成红色，然后所有与该点相连的点全部染成绿色
 * 然后与绿色直接相连的点染成红色，如果存在已经染过的点，则不是二分图
 * **/

#define swap(a, b) {\
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}
#define MAX_N 105
int father[MAX_N];
int size[MAX_N];

void init(int x) {
    for (int i = 0; i < x; i++) {
        father[i] = i;
        size[i] = 1;
    }
    return ;
}

int find(int x) {
    if (x != father[x]) father[x] = find(father[x]);
    return father[x];
}

void merge(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa == fb) return ;
    if (size[fa] > size[fb]) swap(fa, fb);
    father[fa] = fb;
    size[fb] += size[fa];
    return ;
}

bool isConnect(int a, int b) {
    return find(a) == find(b);
}

bool isBipartite(int** graph, int graphSize, int* graphColSize){
    init(graphSize);
    for (int i = 0; i < graphSize; i++) {
        for (int j = 0; j < graphColSize[i]; j++) {
            if (isConnect(i, graph[i][j])) return false;
            else merge(graph[i][0], graph[i][j]);
        }
    }
    return true;
}