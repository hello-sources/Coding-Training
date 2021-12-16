/**
 * 使用Kruskal算法，先把对应的边长度按照从小到大排序
 * 从前向后遍历，如果加入的两个边形成连通，则把边加入进去，根据加入的边进行计数和统计总长度
 * 每次选择加入一个边，维护连通性即可
 * **/

#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

struct Edge {
    int len, x, y;
} Edge;

int cmp(struct Edge *a, struct Edge *b) {
    return a->len - b->len;
}

int find(int *fa, int x) {
    return fa[x] = (fa[x] == x ? x : find(fa, fa[x]));
}

int merge(int *fa, int *size, int a, int b) {
    int A = find(fa, a), B = find(fa, b);
    if (A == B) return 0;
    if (size[A] < size[B]) swap(A, B);
    fa[B] = A;
    size[A] += size[B];
    return 1;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize){
    int n = pointsSize, edgeSize = 0;
    struct Edge edge[(n + 1) * n / 2];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edge[edgeSize].x = i;
            edge[edgeSize].y = j;
            edge[edgeSize++].len = fabs(points[i][0] - points[j][0]) + fabs(points[i][1] - points[j][1]);
        }
    }
    qsort(edge, edgeSize, sizeof(struct Edge), cmp);
    int fa[n], size[n];
    for (int i = 0; i < n; i++) {
        fa[i] = i;
        size[i] = 1;
    }
    int len = 0, num = n;
    for (int i = 0; i < edgeSize; i++) {
        if (merge(fa, size, edge[i].x, edge[i].y)) {
            len += edge[i].len;
            if (++num == n) break;
        }
    }
    return len;
}