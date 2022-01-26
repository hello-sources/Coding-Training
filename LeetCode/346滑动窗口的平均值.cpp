typedef struct {
    double *num;
    int size, cnt;
} MovingAverage;

/** Initialize your data structure here. */

MovingAverage* movingAverageCreate(int size) {
    MovingAverage *obj = (MovingAverage *)malloc(sizeof(MovingAverage));
    obj->num = (double *)malloc(sizeof(double) * (size + 1));
    memset(obj->num, 0, sizeof(double) * (size + 1));
    obj->size = size;
    obj->cnt = obj->cnt = 0;
    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
    if (obj->cnt >= obj->size) {
        for (int i = 1; i < obj->size; i++) {
            obj->num[i - 1] = obj->num[i];
        }
        obj->cnt = obj->size - 1;
    }
    obj->num[obj->cnt++] = val;
    double sum = 0;
    for (int i = 0; i < obj->size; i++) {
        sum += obj->num[i];
    } 
    return sum / obj->cnt;
}

void movingAverageFree(MovingAverage* obj) {
    if (obj == NULL) return ;
    free(obj->num);
    free(obj);
    return ;
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 
 * movingAverageFree(obj);
*/