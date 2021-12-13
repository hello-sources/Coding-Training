#define MAX_N 2505
#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

int father[MAX_N];
int size[MAX_N];

void init(int x) {
    for (int i = 0; i < x; i++) {
        father[i] = i;
        size[i] = 1;
    }
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

int swimInWater(int** grid, int gridSize, int* gridColSize){
    int time = -1, flag = 0, temp = 0;
    init(gridSize * gridColSize[0]);
    while (!flag) {
        time++;
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridColSize[0]; j++) {
                int ind = i * gridColSize[0] + j;
                if (grid[i][j] <= time) {
                    temp = 1;
                    if (i + 1 < gridSize && grid[i + 1][j] <= time) merge(ind, ind + gridColSize[0]);
                    if (j + 1 < gridColSize[0] && grid[i][j + 1] <= time) merge(ind, ind + 1);
                }
            }
        } 
        flag = isConnect(0, gridSize * gridColSize[0] - 1);
    }
    if (!temp) return 0;
    return time;
}