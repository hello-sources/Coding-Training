#define MAX_SIZE 1000005
typedef struct {
    int *data;
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap *obj = (MyHashMap *)malloc(sizeof(MyHashMap));
    obj->data = (int *)malloc(sizeof(int) * MAX_SIZE);
    memset(obj->data, -1, sizeof(int) * MAX_SIZE);
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->data[key] = value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->data[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->data[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/s