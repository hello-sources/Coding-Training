#define MAX_N 20005
typedef struct Heap {
    int apples;
    int days;
} Heap;

Heap **heap;
int heapsize;

void swap(int a, int b) {
    Heap *temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
    return ;
}

void adjust_down() {
    int father = 1;
    int child = 2 * father;
    while (child < heapsize) {
        if (child + 1 < heapsize && heap[child + 1]->days < heap[child]->days) child++;
        if (heap[child]->days > heap[father]->days) break;
        swap(child, father);
        father = child;
        child = father * 2;
    }
    return ;
}

void adjust_up() {
    int child = heapsize - 1;
    int father = child / 2;
    while (father > 0) {
        if (heap[child]->days > heap[father]->days) break;
        swap(child, father);
        child = father;
        father = child / 2;
    }
    return ;
}

void pop() {
    heap[1] = heap[heapsize - 1];
    heapsize--;
    adjust_down();
}

void add(int apples, int days) {
    Heap *h = malloc(sizeof(Heap));
    h->apples = apples;
    h->days = days;
    heap[heapsize++] = h;
    adjust_up();
    return ;
}

bool empty() {
    return heapsize <= 1;
}

Heap *top() {
    return heap[1];
}

int eatenApples(int* apples, int applesSize, int* days, int daysSize){
    int ans = 0;
    for (int i = 0; i < daysSize; i++) {
        days[i] += i;
    }
    heap = malloc(sizeof(Heap *) * (applesSize + 1));
    heapsize = 1;
    int i = 0;
    while (i < daysSize || !empty()) {
        if (i < daysSize) add(apples[i], days[i]);
        while (!empty() && (top()->days  <= i || top()->apples <= 0)) {
            pop();
        }
        i++;
        if (empty()) continue;
        (top()->apples)--;
        ans++;
    }
    return ans;
}