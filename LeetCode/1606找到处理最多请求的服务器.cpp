struct server {
    int idle, min_idle, count;
    struct server *left, *right, *parent;
};

struct server* server_tree_build(struct server servers[], int n, struct server* parent) {
    if (n == 0) return NULL;
    int i = n / 2;
    struct server* root = servers + i;
    root->parent = parent;
    root->left = server_tree_build(servers, i, root);
    root->right = server_tree_build(servers+i+1, n-i-1, root);
    return root;
}

struct server* server_first_idle(struct server* tree, int time) {
    if (tree->left && tree->left->min_idle <= time)
        return server_first_idle(tree->left, time);
    if (tree->idle <= time) return tree;
    return server_first_idle(tree->right, time);
}

struct server* server_next_idle(struct server* srv, int time) {
    if (srv->idle <= time) return srv;
    if (srv->right && srv->right->min_idle <= time)
        return server_first_idle(srv->right, time);
    /* 寻找大于他的祖先 */
    while (srv->parent && srv == srv->parent->right) srv = srv->parent;
    /* srv->parent==NULL || srv == srv->parent->left */
    if (srv->parent == NULL) return NULL;
    else return server_next_idle(srv->parent, time);
}

void server_set_idle(struct server* srv, int time) {
    srv->idle = time;
    while (srv) {
        int new_min_idle = srv->idle;
        if (srv->left && srv->left->min_idle < new_min_idle)
            new_min_idle = srv->left->min_idle;
        if (srv->right && srv->right->min_idle < new_min_idle)
            new_min_idle = srv->right->min_idle;
        if (new_min_idle == srv->min_idle) return;
        srv->min_idle = new_min_idle;
        srv = srv->parent;
    }
}

int* busiestServers(int k, int* arrival, int arrivalSize, int* load, int loadSize, int* returnSize) {
    struct server servers[k];
    memset(servers, 0, sizeof(servers));
    struct server* root = server_tree_build(servers, k, NULL);
    int max_count = 0;

    for (int i=0; i!=arrivalSize; ++i) {
        if (arrival[i] < root->min_idle) continue;
        struct server* srv = 
            server_next_idle(servers+i%k, arrival[i]) ?:
            server_first_idle(root, arrival[i]);
        server_set_idle(srv, arrival[i] + load[i]);
        if (++srv->count > max_count) max_count = srv->count; 
    }
    int* ret = malloc(k * sizeof(int));
    *returnSize = 0;
    for (int i=0; i!=k; ++i) {
        if (servers[i].count == max_count) {
            ret[(*returnSize)++] = i;
        }
    }
    return ret;
}