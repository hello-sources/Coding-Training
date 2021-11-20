typedef struct {
    int size, top[3];
    int *data;
} TripleInOne;


TripleInOne* tripleInOneCreate(int stackSize) {
    TripleInOne *t = (TripleInOne *)malloc(sizeof(TripleInOne));
    t->data = (int *)malloc(sizeof(int) * stackSize * 3);
    t->size = stackSize;
    t->top[0] = -1;
    t->top[1] = -1;
    t->top[2] = -1;
    return t;
}

void tripleInOnePush(TripleInOne* obj, int stackNum, int value) {
    if (obj->top[stackNum] == obj->size - 1) return ;
    obj->top[stackNum]++;
    obj->data[obj->top[stackNum] + obj->size * stackNum] = value;   
}

int tripleInOnePop(TripleInOne* obj, int stackNum) {
    if (obj->top[stackNum] == -1) return -1;
    else {
        int val = obj->data[obj->top[stackNum] + obj->size * stackNum];
        obj->top[stackNum]--;
        return val;
    }
}

int tripleInOnePeek(TripleInOne* obj, int stackNum) {
    if (obj->top[stackNum] == -1) return -1;
    return obj->data[obj->top[stackNum] + stackNum * obj->size];
}

bool tripleInOneIsEmpty(TripleInOne* obj, int stackNum) {
    return obj->top[stackNum] == -1;
}

void tripleInOneFree(TripleInOne* obj) {
    free(obj->data);
    free(obj);
    return ;
}

/**
 * Your TripleInOne struct will be instantiated and called as such:
 * TripleInOne* obj = tripleInOneCreate(stackSize);
 * tripleInOnePush(obj, stackNum, value);
 
 * int param_2 = tripleInOnePop(obj, stackNum);
 
 * int param_3 = tripleInOnePeek(obj, stackNum);
 
 * bool param_4 = tripleInOneIsEmpty(obj, stackNum);
 
 * tripleInOneFree(obj);
*/