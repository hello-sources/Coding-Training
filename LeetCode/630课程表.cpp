#define MAX_N 10005
typedef struct Heap {
    int size;
    int *data;
} Heap;

int cmp(const void *a, const void *b) {
    int *d = *(int **)a;
    int *l = *(int **)b;
    if (l[1] == d[1]) return d[0] - l[0];
    return d[1] - l[1];
}

void push(Heap *heap, int end) {
    heap->data[++heap->size] = end;
    int key = end, i;
    for (i = heap->size; i / 2 >= 1; i /= 2) {
        if (key > heap->data[i >> 1]) {
            heap->data[i] = heap->data[i >> 1];
        } else break;
    }
    heap->data[i] = key;
}

void pop(Heap *heap, int *end) {
    *end = heap->data[1];
    int key = heap->data[heap->size--];
    heap->data[1] = key;
    int i, child;
    for (i = 1; (i * 2) <= heap->size; i = child) {
        child = i * 2;
        if (2 * i < heap->size && heap->data[child] < heap->data[child + 1]) child++;
        if (key < heap->data[child]) {
            heap->data[i] = heap->data[child];
        } else break;
    }
    heap->data[i] = key;
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize){
    qsort(courses, coursesSize, sizeof(courses[0]), cmp);
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 0;
    heap->data = (int *)malloc(sizeof(int) *MAX_N);
    int day = 0, end = 0;
    for (int i = 0; i < coursesSize; i++) {
        if (courses[i][0] + day <= courses[i][1]) {
            push(heap, courses[i][0]);
            day += courses[i][0];
        } else {
            if (heap->size > 0 && heap->data[1] > courses[i][0]) {
                pop(heap, &end);
                day += courses[i][0] - end;
                push(heap, courses[i][0]);
            }
        }
    }
    return heap->size;
}
