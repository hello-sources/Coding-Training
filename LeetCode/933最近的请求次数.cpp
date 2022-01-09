typedef struct {
    int *cnt;
    int tail;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter *r = (RecentCounter *)malloc(sizeof(RecentCounter));
    r->cnt = (int *)malloc(sizeof(int) * 10005);
    r->tail = 0;
    return r;
}

int recentCounterPing(RecentCounter* obj, int t) {
    int tail = obj->tail, count = 0;
    obj->cnt[tail]=t;
    obj->tail += 1;
    for(int i = 0; i <= tail; i++)
    {
        if(obj->cnt[i] >= t - 3000)
        count++;
    }
    return count;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->cnt);
    free(obj);
    return ;
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/