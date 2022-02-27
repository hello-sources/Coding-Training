#define MAX_N 605
typedef struct {
    int *times;
    int cnt;
} HitCounter;


HitCounter* hitCounterCreate() {
    HitCounter *obj = (HitCounter *)malloc(sizeof(HitCounter));
    obj->times = (int *)malloc(sizeof(int) * MAX_N);
    obj->cnt = 0;
    return obj;
}

void hitCounterHit(HitCounter* obj, int timestamp) {
    obj->times[obj->cnt++] = timestamp;
    return ;
}

int hitCounterGetHits(HitCounter* obj, int timestamp) {
    int cnt = 0;
    for (int i = 0; i < obj->cnt; i++) {
        if (timestamp - obj->times[i] < 300) cnt++;
    }
    return cnt;
}

void hitCounterFree(HitCounter* obj) {
    free(obj->times);
    free(obj);
    return ;
}

/**
 * Your HitCounter struct will be instantiated and called as such:
 * HitCounter* obj = hitCounterCreate();
 * hitCounterHit(obj, timestamp);
 
 * int param_2 = hitCounterGetHits(obj, timestamp);
 
 * hitCounterFree(obj);
*/