#define MAX_N 10000

typedef struct {
    int *data;
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack *ms = (MinStack *)malloc(sizeof(MinStack));
    ms->data = (int *)malloc(sizeof(int) * MAX_N);
    ms->top = -1;
    return ms;
}

void minStackPush(MinStack* obj, int val) {
    obj->data[++(obj->top)] = val;
    return ;
}

void minStackPop(MinStack* obj) {
    obj->top -= 1;
    return ;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    int min = INT_MAX;
    for (int i = 0; i <= obj->top; i++) {
        if (min > obj->data[i]) min = obj->data[i];
    }
    return min;
}

void minStackFree(MinStack* obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/