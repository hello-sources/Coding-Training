#define LEN 6   

typedef struct {
    int id;
    char value[LEN];
} OrderedStream;

int ptr, num;

OrderedStream* orderedStreamCreate(int n) {
    OrderedStream *obj = (OrderedStream *)malloc(sizeof(OrderedStream) * (n + 1));
    memset(obj, 0, sizeof(OrderedStream) * (n + 1));
    ptr = 1;
    num = n;
    return obj;
}

char ** orderedStreamInsert(OrderedStream* obj, int idKey, char * value, int* retSize) {
    obj[idKey].id = idKey;
    strcpy(obj[idKey].value, value);
    *retSize = 0;
    if (idKey == ptr) {
        int temp = idKey;
        while (obj[temp].id != 0) {
            temp++;
            if (temp > num) break;
        }
        ptr = temp;
        char **ret = (char **)malloc(sizeof(char *) * (temp - idKey));
        for (int i = idKey; i < temp; i++) {
            ret[(*retSize)] = (char *)malloc(sizeof(char) * LEN);
            strcpy(ret[(*retSize)++], obj[i].value);
        }
        return ret;
    }
    return NULL;
}

void orderedStreamFree(OrderedStream* obj) {
    if (obj == NULL) return ;
    free(obj);
    return ;
}

/**
 * Your OrderedStream struct will be instantiated and called as such:
 * OrderedStream* obj = orderedStreamCreate(n);
 * char ** param_1 = orderedStreamInsert(obj, idKey, value, retSize);
 
 * orderedStreamFree(obj);
*/