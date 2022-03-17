/**************************栈溢出版本************************/
#define MAX_N 50005

typedef struct {
    int *cnt;
    char **ch;
    int min, max, size;
} AllOne;

AllOne* allOneCreate() {
    AllOne *obj = (AllOne *)malloc(sizeof(AllOne));
    obj->cnt = (int *)malloc(sizeof(int) * MAX_N);
    memset(obj->cnt, 0, sizeof(int) * MAX_N);
    obj->ch = (char **)malloc(sizeof(char *) * MAX_N);
    for (int i = 0; i < MAX_N; i++) {
        obj->ch[i] = (char *)malloc(sizeof(char) * 15);
    }
    obj->size = obj->min = obj->max = 0;
    return obj;
}

void allOneInc(AllOne* obj, char * key) {
    if (obj->size == 0) {
        memcpy(obj->ch[obj->size], key, strlen(key));
        obj->cnt[obj->size] = 1;
        obj->max = obj->min = 1;
        obj->size++;
    } else {
        int flag = 0;
        for (int i = 0; i < obj->size; i++) {
            if (strcmp(obj->ch[i], key) == 0) {
                flag = 1;
                obj->cnt[i]++;
                obj->max = fmax(obj->max, obj->cnt[i]);
                obj->min = fmin(obj->min, obj->cnt[i]);
            }
        }
        if (!flag) {
            memcpy(obj->ch[obj->size], key, strlen(key));
            obj->cnt[obj->size] = 1;
            obj->max = fmax(obj->max, obj->cnt[obj->size]);
            obj->min = fmin(obj->min, obj->cnt[obj->size]);
            obj->size++;
        }
    }
    return ;
}

void allOneDec(AllOne* obj, char * key) {
    for (int i = 0; i < obj->size; i++) {
        if (strcmp(key, obj->ch[i]) == 0) obj->cnt[i]--;
    }
    for (int i = 1; i < obj->size; i++) {
        if (obj->cnt[i - 1] == 0) {
            memcpy(obj->ch[i - 1], obj->ch[i], strlen(obj->ch[i]));
            obj->max = fmax(obj->max, obj->cnt[i - 1]);
            obj->min = fmin(obj->min, obj->cnt[i - 1]);
            obj->cnt[i] = obj->cnt[i - 1];
        }
    }
    return ;
}

char * allOneGetMaxKey(AllOne* obj) {
    for (int i = 0; i < obj->size; i++) {
        if (obj->max == obj->cnt[i]) return obj->ch[i];
    }
    return NULL;
}

char * allOneGetMinKey(AllOne* obj) {
    for (int i = 0; i < obj->size; i++) {
        if (obj->min == obj->cnt[i]) return obj->ch[i];
    }
    return NULL;
}

void allOneFree(AllOne* obj) {
    free(obj->cnt);
    free(obj->ch);
    free(obj);
    return ;
}

/**
 * Your AllOne struct will be instantiated and called as such:
 * AllOne* obj = allOneCreate();
 * allOneInc(obj, key);
 
 * allOneDec(obj, key);
 
 * char * param_3 = allOneGetMaxKey(obj);
 
 * char * param_4 = allOneGetMinKey(obj);
 
 * allOneFree(obj);
*/


/*************************大佬的UtHash版本**********************/
typedef struct date{
	int n;
	char* key;
	struct date* pre;
	struct date* next;
	UT_hash_handle hh;
} AllOne;
struct date* users = NULL;
/** Initialize your data structure here. */
AllOne* allOneCreate() {
	struct date* obj = (struct date*)malloc(sizeof(struct date));
	struct date* tail = (struct date*)malloc(sizeof(struct date));
	obj->n = 0;
	obj->pre = tail;
	obj->next = tail;
	tail->n = INT_MAX;
	tail->pre = obj;
	tail->next = obj;
	return obj;
}
/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
void allOneInc(AllOne* obj, char * key) {
	struct date* node = NULL;
	HASH_FIND_STR(users, key, node);
	if (!node){
		node = (struct date*)malloc(sizeof(struct date));
		node->n = 1;
		node->key = key;
		node->pre = obj;
		node->next = obj->next;
		obj->next->pre = node;
		obj->next = node;
        HASH_ADD_STR(users, key, node);
	}
	else{
		node->n++;
		while (node->n > node->next->n){
			struct date* t = node->next;
            t->next->pre = node;
            node->pre->next = t;
			node->next = t->next;
			t->pre = node->pre;
			t->next = node;
			node->pre = t;
		}
	}
}
/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
void allOneDec(AllOne* obj, char * key) {
	struct date* node = NULL;
	HASH_FIND_STR(users, key, node);
	if (node){
		if (node->n > 1){
			node->n--;
			while (node->n < node->pre->n){
				struct date* t = node->pre;
                t->pre->next = node;
                node->next->pre = t;
				node->pre = t->pre;
				t->pre = node;
				t->next = node->next;
				node->next = t;
			}
		}
		else{
			node->pre->next = node->next;
			node->next->pre = node->pre;
			HASH_DEL(users, node);
			free(node);
		}
	}
}
/** Returns one of the keys with maximal value. */
char * allOneGetMaxKey(AllOne* obj) {
	if (obj->pre->pre->n)
		return obj->pre->pre->key;
	return "";
}
/** Returns one of the keys with Minimal value. */
char * allOneGetMinKey(AllOne* obj) {
	if (obj->next->n < INT_MAX)
		return obj->next->key;
	return "";
}
void allOneFree(AllOne* obj) {
	struct date *current_user, *tmp;
	HASH_ITER(hh, users, current_user, tmp) {
		HASH_DEL(users, current_user);
		free(current_user); 
	}
	struct date *t = obj->pre;	
	free(t);
    free(obj);
	obj = NULL;
}