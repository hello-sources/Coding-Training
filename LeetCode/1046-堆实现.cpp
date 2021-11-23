#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \    
}

void push(int *heap, int *heapSize, int val) {
    heap[++(*heapSize)] = val;
    for (int i = (*heapSize); i > 1 && heap[i] > heap[i >> 1]; i >>= 1) {
        swap(heap[i], heap[i >> 1]);
    }
    return ;
}

void pop(int *heap, int *heapSize) {
    int temp = heap[1] = heap[(*heapSize)--];
    int i = 1, j = 2;
    while (j <= (*heapSize)) {
        if (j != (*heapSize) && heap[j + 1] > heap[j]) ++j;
        if (heap[j] <= temp) break;
        heap[i] = heap[j];
        i = j;
        j = i << 1;
    }
    heap[i] = temp;
    return ;
}

int top(int *heap) {
    return heap[1];
}

int lastStoneWeight(int* stones, int stonesSize){
    if (stonesSize == 1) return stones[0];
    if (stonesSize == 2) return fabs(stones[0] - stones[1]);
    int heap[stonesSize + 2], heapSize = 0;
    for (int i = 0; i < stonesSize; i++) {
        push(heap, &heapSize, stones[i]);
    }
    while (heapSize > 1) {
        int a = top(heap);
        pop(heap, &heapSize);
        int b = top(heap);
        pop(heap, &heapSize);
        if (a > b) push(heap, &heapSize, a - b);
    }
    return heapSize ? top(heap) : 0;
}