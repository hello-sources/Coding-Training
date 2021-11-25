/********数组hash法**********/
typedef struct {
    int *data;
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet *hash = (MyHashSet *)malloc(sizeof(MyHashSet));
    hash->data = (int *)malloc(sizeof(int) * 1000005);
    memset(hash->data, 0xff, sizeof(int) * 1000005);
    return hash;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if (obj->data[key] == -1) {
        obj->data[key] = key;
    }
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->data[key] = -1;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->data[key] != -1;
}

void myHashSetFree(MyHashSet* obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}


/**************链地址法（要了老命了）****************/
#define MAX_SIZE 769
typedef struct Node {
    int val;
    struct Node *next;
} List;

typedef struct {
    List *hash[MAX_SIZE];
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet *obj = (MyHashSet *)malloc(sizeof(MyHashSet));
    for (int i = 0; i < MAX_SIZE; i++) {
        obj->hash[i] = (List *)malloc(sizeof(List));
        obj->hash[i]->val = i;
        obj->hash[i]->next = NULL;
    }
    return obj;
}

void addList(List *list, int val) {
    List *temp = list->next;
    List *new = (List *)malloc(sizeof(List));
    new->val = val;
    list->next = new;
    new->next = temp;
    return ;
}

void removeList(List *list, int val) {
    List *cur = list->next;
    List *pre = list;
    while (cur != NULL) {
        if (cur->val == val) {
            pre->next = cur->next;
            free(cur);
            return ;
        }
        pre = cur;
        cur = cur->next;
    }
    return ;
}

bool isListContains(List *list, int val) {
    List *cur = list->next;
    while (cur) {
        if (cur->val == val) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

void freeList(List *list) {
    List *cur = list;
    List *temp = NULL;
    while (cur) {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if (isListContains(obj->hash[key % MAX_SIZE], key)) return ;
    addList(obj->hash[key % MAX_SIZE], key);
}

void myHashSetRemove(MyHashSet* obj, int key) {
    removeList(obj->hash[key % MAX_SIZE], key);
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return isListContains(obj->hash[key % MAX_SIZE], key);
}

void myHashSetFree(MyHashSet* obj) {
    for (int i = 0; i < MAX_SIZE; i++) {
        freeList(obj->hash[i]);
    }
    free(obj);
    return ;
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/