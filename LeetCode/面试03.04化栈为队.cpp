#define MAX_SIZE 100

typedef struct {
    int *stackA, *stackB;
    int topA, topB, count;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *mq = (MyQueue *)malloc(sizeof(MyQueue));
    if (mq == NULL) return NULL;
    mq->stackA = (int *)malloc(sizeof(int) * MAX_SIZE);
    if (mq->stackA == NULL) {
        free(mq);
        return NULL;
    }
    mq->topA = -1;
    mq->stackB = (int *)malloc(sizeof(int) * MAX_SIZE);
    if (mq->stackB == NULL) {
        free(mq);
        return NULL;
    }
    mq->topB = -1;
    mq->count = 0;
    return mq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if (obj->topA == -1) {
        while (obj->topB != -1) {
            obj->stackA[++obj->topA] = obj->stackB[obj->topB--];
        }
    }
    obj->stackA[++obj->topA] = x;
    obj->count++;
    return ;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (obj->topB == -1) {
        while (obj->topA != -1) {
            obj->stackB[++obj->topB] = obj->stackA[obj->topA--];
        }
    }
    obj->count--;
    return obj->stackB[obj->topB--];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (obj->topB == -1) {
        while (obj->topA != -1) {
            obj->stackB[++obj->topB] = obj->stackA[obj->topA--];
        }
    }
    return obj->stackB[obj->topB];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return !obj->count;
}

void myQueueFree(MyQueue* obj) {
    if (obj == NULL) return ;
    free(obj->stackA);
    free(obj->stackB);
    free(obj);
    return ;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/