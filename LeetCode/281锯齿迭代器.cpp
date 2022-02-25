struct ZigzagIterator {
    int *num;
    int next, len;
};

struct ZigzagIterator *zigzagIteratorCreate(int* v1, int v1Size, int* v2, int v2Size) {
    struct ZigzagIterator *obj = (struct ZigzagIterator *)malloc(sizeof(struct ZigzagIterator));
    obj->num = (int *)malloc(sizeof(int) * (v1Size + v2Size));
    obj->len = v1Size + v2Size;
    obj->next = 0;
    int ind = 0;
    for (int i = 0; i < v1Size + v2Size; i++) {
        if (i < v1Size) {
            obj->num[ind++] = v1[i];
        }
        if (i < v2Size) {
            obj->num[ind++] = v2[i];
        }
    }
    return obj;
}

bool zigzagIteratorHasNext(struct ZigzagIterator *iter) {
    return iter->next < iter->len;
}

int zigzagIteratorNext(struct ZigzagIterator *iter) {
    return iter->num[iter->next++];
}

/** Deallocates memory previously allocated for the iterator */
void zigzagIteratorFree(struct ZigzagIterator *iter) {
    free(iter->num);
    free(iter);
    return ;
}

/**
 * Your ZigzagIterator will be called like this:
 * struct ZigzagIterator *i = zigzagIteratorCreate(v1, v1Size, v2, v2Size);
 * while (zigzagIteratorHasNext(i)) printf("%d\n", zigzagIteratorNext(i));
 * zigzagIteratorFree(i);
 */