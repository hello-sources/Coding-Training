#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

typedef struct Priority_Queue {
    int *data;
    int cnt, size;
} Priority_Queue;

Priority_Queue *init(int n) {
    Priority_Queue *heap = (Priority_Queue *)malloc(sizeof(Priority_Queue));
    heap->data = (int *)malloc(sizeof(int) * (n + 2));
    heap->cnt = 0;
    heap->size = n;
    return heap;
}

int empty(Priority_Queue *heap) {
    return heap->cnt == 0;
}

int top(Priority_Queue *heap) {
    return heap->data[1];
}

int push(Priority_Queue *heap, int val) {
    if (heap == NULL) return 0;
    if (heap->cnt == heap->size) return 0;
    heap->data[++(heap->cnt)] = val;
    int ind = heap->cnt;
    while (ind << 1 && heap->data[ind] > heap->data[ind << 1]) {
        swap(heap->data[ind], heap->data[ind << 1]);
        ind <<= 1;
    }
    return 1;
}

int pop(Priority_Queue *heap) {
    if (heap == NULL) return 0;
    if (empty(heap)) return 0;
    heap->data[1] = heap->data[(heap->cnt)--];
    int ind = 1;
    while ((ind << 1) <= heap->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (heap->data[temp] < heap->data[l]) temp = l;
        if (heap->data[r] > heap->data[temp] && r <= heap->cnt) temp = r;
        if (temp == ind) break;
        swap(heap->data[temp], heap->data[ind]);
        ind = temp;
    }
    return 1;
}

void clear(Priority_Queue *heap) {
    if (heap == NULL) return ;
    free(heap->data);
    free(heap);
    return ;
}


/* heap sort*/

void downUpdate(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[temp] > arr[l]) temp = l;
        if (arr[temp] > arr[r] && r <= n) temp = r;
        if (temp == ind) break;
        swap(arr[ind], arr[temp]);
        ind = temp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i>= 1; i--) {
        downUpdate(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[i], arr[1]);
        downUpdate(arr, i - 1, 1);
    }
    return ;
}

void Output_Heap_Sort(int *arr, int n) {
    printf("arr(%d) = [", n);
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    //Prtiority_Queue
    Priority_Queue *heap = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        push(heap, val);
        printf("insert %d to queue succeed!\n", val);
    }
    for (int i = 0; i < MAX_OP; i++) {
        printf("%d ", top(heap));
        pop(heap);
    }
    printf("\n");
    clear(heap);
    
    //heap_sort
    int *arr = (int *)malloc(sizeof(int) * MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        arr[i] = val;
    }
    Output_Heap_Sort(arr, MAX_OP);
    heap_sort(arr, MAX_OP);
    printf("here\n");
    Output_Heap_Sort(arr, MAX_OP);
    free(arr);
    return 0;
}