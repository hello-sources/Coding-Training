/*DP做法*/
int min(int a, int b) {
    return a > b ?b :a;
}

int nthUglyNumber(int n){
    int  num[n + 1];
    int ind2 = 1;
    int ind3 = 1;
    int ind5 = 1;
    num[1] = 1;
    for (int i = 2; i <= n; i++) {
        num[i] = min(min(num[ind2] * 2, num[ind3] * 3), num[ind5] * 5);
        while (num[i] >= num[ind2] * 2) ++ind2;
        while (num[i] >= num[ind3] * 3) ++ind3;
        while (num[i] >= num[ind5] * 5) ++ind5;
    }
    return num[n];
}

/*最小堆做法*/
#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

typedef struct Heap {
    long long *data;
    int n, size;
} Heap;

Heap *init(int n) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->n = 0;
    h->size = n + 1;
    h->data = (long long *)malloc(sizeof(long long) * h->size);
    return h;
}

int empty(Heap *h) {
    return h->n == 0;
}

#define V(x) h->data[x]

void push(Heap *h, long long val) {
    h->data[++(h->n)] = val;
    int ind = h->n;
    while (ind > 1 && V(ind) < V(ind >> 1)) {
        swap(V(ind), V(ind >> 1));
        ind >>= 1;
    }
    return ;
}

long long top(Heap *h) { return V(1); }

void pop(Heap *h) {
    if (empty(h)) return ;
    V(1) = V(h->n);
    (h->n)--;
    int ind = 1;
    while ((ind << 1) <= h->n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (V(l) < V(temp)) temp = l;
        if (r <= h->n && V(r) < V(temp)) temp = r;
        if (temp == ind) break;
        swap(V(ind), V(temp));
        ind = temp;
    }
    return ;
}

void clear(Heap *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h);
    return ;
}

int nthUglyNumber(int n){
    Heap *h = init(3 * n);
    push(h, 1);
    long long ans = 0;
    while (n--) {
        ans = top(h);
        pop(h);
        if (ans % 5 == 0) {
            push(h, 5 * ans);
        } else if (ans % 3 == 0) {
            push(h, 3 * ans);
            push(h, 5 * ans);
        } else {
            push(h, 2 * ans);
            push(h, 3 * ans);
            push(h, 5 * ans);
        }
    }
    clear(h);
    return ans;
}