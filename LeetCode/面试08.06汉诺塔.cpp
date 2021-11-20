/***********面向答案编程*************/
void hanota(int* A, int ASize, int* B, int BSize, int** C, int* CSize){
    *CSize = ASize;
    *C = A;
}

/***********C语言手写栈解决汉诺塔问题**********/
typedef struct Stack {
    int *data;
    int size;
} Stack;

bool push(Stack *s, int val) {
    s->data[(s->size)++] = val;
    return true;
}

bool pop(Stack *s) {
    s->size--;
    return true;
}

int top(Stack *s) {
    return s->data[s->size - 1];
}

void hanotaCal(int n, Stack *a, Stack *b, Stack *c) {
    if (n == 1) {
        push(c, top(a));
        pop(a);
        return ;
    }
    hanotaCal(n - 1, a, c, b);
    hanotaCal(1, a, b, c);
    hanotaCal(n - 1, b, a, c);
}

void hanota(int* A, int ASize, int* B, int BSize, int** C, int* CSize){
    if (ASize <= 0) return ;
    Stack *a = (Stack *)malloc(sizeof(Stack));
    Stack *b = (Stack *)malloc(sizeof(Stack));
    Stack *c = (Stack *)malloc(sizeof(Stack));
    a->data = (int *)malloc(sizeof(int) * 1000);
    a->size = 0;
    for (int i =0; i < ASize; i++) {
        push(a, A[i]);
    }
    b->data = (int *)malloc(sizeof(int) * 1000);
    b->size = 0;
    c->data = (int *)malloc(sizeof(int) * 1000);
    c->size = 0;
    hanotaCal(ASize, a, b, c);
    *C = c->data;
    *CSize = c->size;
    free(a->data);
    free(b->data);
}