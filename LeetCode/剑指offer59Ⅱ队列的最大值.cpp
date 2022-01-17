#define MAX_N 20005
typedef struct {
    int head, tail;
    int *steps;
} MaxQueue;


MaxQueue* maxQueueCreate() {
    MaxQueue *obj = (MaxQueue *)malloc(sizeof(MaxQueue));
    obj->steps = (int *)malloc(sizeof(int) * MAX_N);
    // obj->max = 0;
    obj->head = obj->tail = 0;
    return obj;
}

int maxQueueMax_value(MaxQueue* obj) {
    int max = -1;
    if (obj->head == obj->tail) return -1;
    for (int i = obj->head; i <= obj->tail; i++) {
        max = fmax(max, obj->steps[i]);
    }
    return max;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    obj->steps[obj->tail++] = value;
    // obj->max = fmax(obj->max, value);
    return ;
}

int maxQueuePop_front(MaxQueue* obj) {
    if (obj->head == obj->tail) return -1;
    return obj->steps[obj->head++];
}

void maxQueueFree(MaxQueue* obj) {
    if (obj == NULL) return ;
    free(obj->steps);
    free(obj);
    return ;
}

/**
 * Your MaxQueue struct will be instantiated and called as such:
 * MaxQueue* obj = maxQueueCreate();
 * int param_1 = maxQueueMax_value(obj);
 
 * maxQueuePush_back(obj, value);
 
 * int param_3 = maxQueuePop_front(obj);
 
 * maxQueueFree(obj);
*/