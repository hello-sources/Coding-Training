int dfs(int node, long * maxScore, int * cnt, int n, const struct ListNode ** children) {
    long score = 1;
    int size = n - 1;
    for (struct ListNode * curr = children[node]; curr; curr = curr->next) {
        int t = dfs(curr->val, maxScore, cnt, n, children);
        score *= t;
        size -= t;
    }
    if (node != 0) {
        score *= size;
    }
    if (score == *maxScore) {
        (*cnt)++;
    } else if (score > *maxScore) {
        *maxScore = score;
        *cnt = 1;
    }
    return n - size;
}

int countHighestScoreNodes(int* parents, int parentsSize){
    int n = parentsSize;
    int cnt = 0;
    long maxScore = 0;
    struct ListNode ** children = (struct ListNode **)malloc(sizeof(struct ListNode *) * n);
    for (int i = 0; i < n; i++) {
        children[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        int p = parents[i];
        if (p != -1) {
            struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
            node->val = i;
            node->next = children[p];
            children[p] = node;
        }
    }
    dfs(0, &maxScore, &cnt, n, children);
    // for (int i = 0; i < n; i++) {
    //     for (struct ListNode * curr = children[i]; curr; ) {
    //         struct ListNode * next = curr->next;
    //         free(curr);
    //         curr = next;
    //     }
    // }
    free(children);
    return cnt;
}