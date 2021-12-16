/***
 * 典型的并查集算法， 值得注意的是需要做一个优化
 * 先把对应字符串按照先排==，然后再排!=号，这样就会使前面的先merge,然后后面判断是否相等
*/

int find(int *fa, int x) {
    return fa[x] = (fa[x] == x ? x : find(fa, fa[x]));
}

void merge(int *fa, int a, int b) {
    int A = find(fa, a), B = find(fa, b);
    if (A == B) return ;
    fa[B] = A;
    return ;
}

int cmp(const void *a, const void *b) {
    char *fa = *(char **)a;
    char *fb = *(char **)b;
    return fb[1] - fa[1];
}

bool equationsPossible(char ** equations, int equationsSize){
    qsort(equations, equationsSize, sizeof(char *), cmp);
    int fa[26];
    for (int i = 0; i < 26; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '=') {
            merge(fa, equations[i][0] - 'a', equations[i][3] - 'a');
        } else {
            int temp1 = find(fa, equations[i][0] - 'a');
            int temp2 = find(fa, equations[i][3] - 'a');
            if (temp1 == temp2) return false;
        }
    }
    return true;
}