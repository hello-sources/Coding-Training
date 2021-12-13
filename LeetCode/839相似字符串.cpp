/**
 * 得学会抽象分析问题，看似是判断有多少个“相似”的单词（相似定义在于同样字母组成两个位置只有两个不同的字符串）
 * 如果两个字符串相似，那么就把这两个字符串给连通起来，题目问有多少组不相似的字符串组
 * 其实就可以抽象为有多少个连通分量，通过判断两个字符串是否相似，从而把对应角标给merge一下，
 * 最后只需要统计初始化染色，而且颜色并未变的角标就OK了
*/

int find(int *fa, int x) {
    return fa[x] = (fa[x] == x ? x : find(fa, fa[x]));
}

bool judge(char *s1, char *s2, int len) {
    int cnt = 0;
    for (int i = 0; i <len; i++) {
        if (s1[i] - s2[i]) cnt++;
        if (cnt > 2) return false;
    }
    return true;
}

int numSimilarGroups(char ** strs, int strsSize){
    int len = strlen(strs[0]), cnt = 0;
    int fa[strsSize];
    for (int i = 0; i < strsSize; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < strsSize; i++) {
        for (int j = i + 1; j < strsSize; j++) {
            int fi = find(fa, i), fj = find(fa, j);
            if (fi == fj) continue;
            if (judge(strs[i], strs[j], len)) fa[fi] = fj;
        }
    }
    for (int i = 0; i < strsSize; i++) {
        if (fa[i] == i) cnt++;
    }
    return cnt;
}