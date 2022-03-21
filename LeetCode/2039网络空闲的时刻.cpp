static inline int max(int x, int y) {
    return x > y ? x : y;
}

int networkBecomesIdle(int** edges, int edgesSize, int* edgesColSize, int* patience, int patienceSize) {
    int n = patienceSize;
    struct ListNode ** adj = (struct ListNode **)malloc(sizeof(struct ListNode * ) * n);
    bool * visit = (bool *)malloc(sizeof(bool) * n);
    for (int i = 0; i < n; i++) {
        visit[i] = false;
        adj[i] = NULL;
    }
    struct ListNode * node = NULL;
    for (int i = 0; i < edgesSize; i++) {
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = edges[i][0];
        node->next = adj[edges[i][1]];
        adj[edges[i][1]] = node;
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = edges[i][1];
        node->next = adj[edges[i][0]];
        adj[edges[i][0]] = node;
    }

    int * queue = (int *)malloc(sizeof(int) * n);
    int head = 0;
    int tail = 0;
    queue[tail++] = 0;
    visit[0] = true;
    int dist = 1;
    int ans = 0;
    while (head != tail) {
        int sz = tail - head;
        for (int i = 0; i < sz; ++i) {
            int curr = queue[head];
            head++;
            for (struct ListNode * node = adj[curr]; node; node = node->next) {
                int v = node->val;
                if (visit[v]) {
                    continue;
                }
                queue[tail++] = v;
                int time = patience[v] * ((2 * dist - 1) / patience[v]) + 2 * dist + 1;
                ans = max(ans, time);
                visit[v] = true;
            }
        }
        dist++;
    }
    free(queue);
    free(visit);
    for (int i = 0; i < n; i++) {
        for (struct ListNode * curr = adj[i]; curr;) {
            struct ListNode * next = curr->next;
            free(curr);
            curr = next;
        }
    }
    return ans;
}