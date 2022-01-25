struct Node {
    int val;
    struct Node *next;
};

struct Node *lst_alloc() {
    struct Node *ret = (struct Node *)malloc(sizeof(struct Node));
    memset(ret, 0, sizeof(struct Node));
    return ret;
}

void lst_free(struct Node *lst) {
    while (lst != NULL) {
        struct Node *tmp = lst->next;
        free(lst);
        lst = tmp;
    }
}

void lst_push_front(struct Node **plst, int val) {
    struct Node *node = lst_alloc();
    node->val = val;
    node->next = *plst;
    *plst = node;
}

struct Pair {
    int node;
    int len;
};

int secondMinimum(int n, int** edges, int edgesSize, int* edgesColSize, int time, int change) {
    struct Node **graph = (struct Node **)malloc((n + 1) * sizeof(struct Node *));
    memset(graph, 0, (n + 1) * sizeof(struct Node *));
    for (int i = 0; i < edgesSize; i++) {
        lst_push_front(&graph[edges[i][0]], edges[i][1]);
        lst_push_front(&graph[edges[i][1]], edges[i][0]);
    }

    // path[i] 表示从 1 到 i 的最短路长度，path[i+n] 表示从 1 到 i 的严格次短路长度
    int *path = (int *)malloc((2 * n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        path[i] = INT_MAX;
        path[i + n] = INT_MAX;
    }

    struct Pair *queue = (struct Pair *)malloc((2 * n + 1) * sizeof(struct Pair));
    int front = 0, back = 0;

    path[1] = 0;
    queue[back].node = 1;
    queue[back++].len = 0;

    while (path[n + n] == INT_MAX) {
        int cur = queue[front].node;
        int len = queue[front++].len;
        struct Node *next = graph[cur];
        while (next) {
            if (len + 1 < path[next->val]) {
                path[next->val] = len + 1;
                queue[back].node = next->val;
                queue[back++].len = len + 1;
            } else if (len + 1 > path[next->val] && len + 1 < path[next->val + n]) {
                path[next->val + n] = len + 1;
                queue[back].node = next->val;
                queue[back++].len = len + 1;
            }
            next = next->next;
        }
    }

    int ret = 0;
    for (int i = 0; i < path[n + n]; i++) {
        if (ret % (2 * change) >= change) {
            ret = ret + 2 * change - ret % (2 * change);
        }
        ret = ret + time;
    }

    free(queue);
    free(path);
    for (int i = 1; i <= n; i++) {
        lst_free(graph[i]);
    }
    free(graph);

    return ret;
}