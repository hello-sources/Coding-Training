typedef struct {
    int size, cnt, front, end, sum;
    int *num;
} MovingAverage;


MovingAverage* movingAverageCreate(int size) {
    MovingAverage *obj = (MovingAverage *)malloc(sizeof(MovingAverage));
    obj->size = size;
    obj->cnt = 0;
    obj->front = obj->end = -1;
    obj->sum = 0;
    obj->num = (int *)malloc(sizeof(int) * (obj->size + 5));
    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
    if (obj->front == -1 && obj->end == -1) {
        obj->front++;
        obj->end++;
        obj->num[obj->end] = val;
        obj->cnt++;
        obj->sum = val;
        return val;
    } else if ((obj->end + 1) % obj->size == obj->front) {
        obj->sum -= obj->num[obj->front];
        obj->front = (obj->front + 1) % obj->size;
        obj->cnt--;
    }
    obj->end = (obj->end + 1) % obj->size;
    obj->num[obj->end] = val;
    obj->sum += val;
    obj->cnt++;
    return (double)obj->sum / obj->cnt;
}

void movingAverageFree(MovingAverage* obj) {
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