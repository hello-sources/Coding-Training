typedef struct {
    int val;
    char str[55];
    UT_hash_handle hh;
} MapSum;

MapSum *g_map = NULL;

MapSum* mapSumCreate() {
    return g_map;
}

void mapSumInsert(MapSum* obj, char *str, int val) {
    MapSum *s = NULL;
    HASH_FIND_STR(g_map, str, s);
    if (s == NULL) {
        s = (MapSum *)malloc(sizeof(MapSum));
        strcpy(s->str, str);
        s->val = val;
        HASH_ADD_STR(g_map, str, s);
    } else {
        s->val = val;
    }
    return ;
}

int mapSumSum(MapSum* obj, char * prefix) {
    int sum = 0;
    MapSum *iter, *temp;
    HASH_ITER(hh, g_map, iter, temp) {
        if (strstr(iter->str, prefix) == iter->str) sum += iter->val;
    }
    return sum;
}

void mapSumFree(MapSum* obj) {
    MapSum *iter, *temp;
    HASH_ITER(hh, g_map, iter, temp) {
        HASH_DEL(g_map, iter);
        free(iter);
    }
    return ;
}

/**
 * Your MapSum struct will be instantiated and called as such:
 * MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);
 
 * int param_2 = mapSumSum(obj, prefix);
 
 * mapSumFree(obj);
*/