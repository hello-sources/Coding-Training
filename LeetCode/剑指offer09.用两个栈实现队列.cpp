#define MAX_SIZE 10005
typedef struct {
    int *stackA, *stackB;
    int topA, topB;
} CQueue;


CQueue* cQueueCreate() {
    CQueue *cq = (CQueue *)malloc(sizeof(CQueue));
    if (cq == NULL) return NULL;
    cq->stackA = (int *)malloc(sizeof(int) * MAX_SIZE);
    if (cq->stackA == NULL) {
        free(cq);
        return NULL;
    }
    cq->topA = -1;

    cq->stackB = (int *)malloc(sizeof(int) * MAX_SIZE);
    if (cq->stackB == NULL) {
        free(cq);
        return NULL;
    } 
    cq->topB = -1;
    return cq;
}

void cQueueAppendTail(CQueue* obj, int value) {
    if (obj->topA != MAX_SIZE) {
        obj->stackA[++obj->topA] = value;
    }
    return ;
}

int cQueueDeleteHead(CQueue* obj) {
    int A = 0, B = 0;
    if (obj->topB != -1) {
        B = obj->stackB[obj->topB--];
        return B;
    }
    if (obj->topB == -1 && obj->topA != -1) {
        while (obj->topA != -1) {
            A = obj->stackA[obj->topA--];
            obj->stackB[++obj->topB] = A;
        }
    }
    if (obj->topB != -1) {
        B = obj->stackB[obj->topB--];
        return B;
    }
    return -1;
}

void cQueueFree(CQueue* obj) {
    if (obj == NULL) return ;
    if (obj->stackA != NULL) free(obj->stackA);
    if (obj->stackB != NULL) free(obj->stackB);
    free(obj);
    return ;
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/