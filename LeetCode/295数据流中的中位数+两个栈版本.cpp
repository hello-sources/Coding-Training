#define MAX_N 50005

typedef struct {
    int *stack1;
    int *stack2;
    int top1, top2;
    double mid;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder *m = (MedianFinder *)malloc(sizeof(MedianFinder));
    m->stack1 = (int *)malloc(sizeof(int) * MAX_N);
    m->top1 = -1;
    m->stack2 = (int *)malloc(sizeof(int) * MAX_N);
    m->top2 = -1;
    m->mid = 0;
    return m;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->top1 == -1 && obj->top2 == -1) {
        obj->stack1[++obj->top1] = num;
        obj->mid = num;
        return ;
    } else if (obj->top1 >= 0 && num < obj->stack1[obj->top1]) {
        while (obj->top1 >= 0 && num < obj->stack1[obj->top1]) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
        obj->stack1[++obj->top1] = num;
    } else if (obj->top1 >= 0 && num == obj->stack1[obj->top1]) {
        obj->stack1[++obj->top1] = num;
    } else if (obj->top1 >= 0 && num > obj->stack1[obj->top1]) {
        if (obj->top2 == -1) {
            obj->stack1[++obj->top1] = num;
        } else {
            if (num <= obj->stack2[obj->top2]) {
                obj->stack1[++obj->top1] = num;
            } else {
                while (obj->top2 >= 0 && num > obj->stack2[obj->top2]) {
                    obj->stack1[++obj->top1] = obj->stack2[obj->top2--];
                }
                obj->stack2[++obj->top2] = num;
            }
        }
    }
    int sum = obj->top1 + obj->top2 + 2;
    if (sum % 2 == 1) {
        int mid = sum / 2 + 1;
        if (mid <= obj->top1 + 1) {
            obj->mid = 1.0 * obj->stack1[mid - 1];
        } else {
            obj->mid = 1.0 * obj->stack2[obj->top2 + 1 - (mid - obj->top1 - 1)];
        }
    } else {
        int mid1 = sum / 2, mid2 = sum / 2 + 1;
        if (mid2 <= obj->top1 + 1) {
            obj->mid = 1.0 * (obj->stack1[mid1 - 1] + obj->stack1[mid2 - 1]) / 2.0;
        } else if (mid1 <= obj->top1 + 1 && mid2 > obj->top1 + 1) {
            obj->mid = 1.0 * (obj->stack1[mid1 - 1] + obj->stack2[obj->top2 + 1 - (mid2 - obj->top1 - 1)]) / 2.0;
        } else if (mid1 > obj->top1 + 1) {
            obj->mid = 1.0 * (obj->stack2[obj->top2 + 1 - (mid1 - obj->top1 - 1)] + obj->stack2[obj->top2 + 1 - (mid2 - obj->top1 - 1)]) / 2.0;
        }
    }
    return ;
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->top1 == -1 && obj->top2 == -1) return 0;
    return obj->mid;
}

void medianFinderFree(MedianFinder* obj) {
    if (obj == NULL) return ;
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
    return ;
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/