/**
 * 使用结构体封装并查集，使用两个并查集，其中，公共边是必须用到的
 * 优先使用公共边，如果加入这两个点没连通，则合并这两个连通分量
 * 处理完公共边，接下来就要处理独占边了，对于Alice与Bob两者是等价的
 * 随后 Alice 不断地向并查集中添加「Alice 独占边」，
 * Bob 不断地向并查集中添加「Bob 独占边」。
 * 在处理完了所有的独占边之后，如果这两个并查集都只包含一个连通分量，
 * 那么就说明 Alice 和 Bob 都可以遍历整个无向图。
 * 注意：
 * 即需要合并的两个点属于同一个连通分量，那么就说明当前这条边可以被删除，将答案增加 1
 * **/


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return ;
}

typedef struct My_Union {
    int *fa, *size;
    int n, cnt;
} My_Union;

void init(struct My_Union *obj, int n) {
    obj->fa = (int *)malloc(sizeof(int) * n);
    obj->size = (int *)malloc(sizeof(int) * n);
    obj->n = n;
    obj->cnt = n;
    for (int i = 0; i < n; i++) {
        obj->fa[i] = i;
        obj->size[i] = 1;
    }
    return ;
}

int find(struct My_Union *obj, int x) {
    return obj->fa[x] = (obj->fa[x] == x ? x : find(obj, obj->fa[x]));
}

int merge(struct My_Union *obj, int a, int b) {
    int fa = find(obj, a), fb = find(obj, b);
    if (fa == fb) return 0;
    if (obj->size[fa] < obj->size[fb]) swap(&fa, &fb);
    obj->fa[fb] = fa;
    obj->size[fa] += obj->size[fb];
    obj->cnt--;
    return 1;
}

int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize){
    My_Union *uA = (My_Union *)malloc(sizeof(My_Union));
    My_Union *uB = (My_Union *)malloc(sizeof(My_Union));
    init(uA, n);
    init(uB, n);
    int ans = 0;
    for (int i = 0; i < edgesSize; i++) {
        edges[i][1]--;
        edges[i][2]--;
    }
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][0] == 3) {
            if (!merge(uA, edges[i][1], edges[i][2])) ans++;
            else merge(uB, edges[i][1], edges[i][2]);
        }
    }
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][0] == 1) {
            if (!merge(uA, edges[i][1], edges[i][2])) ans++;
        } else if (edges[i][0] == 2) {
            if (!merge(uB, edges[i][1], edges[i][2])) ans++;
        }
    }
    if (uA->cnt != 1 || uB->cnt != 1) return -1;
    return ans;
}