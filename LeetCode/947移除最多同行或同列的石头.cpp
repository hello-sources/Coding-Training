/**
 * 对于该问题，使用并查集进行，求解，首先要解决的是连通性问题
 * 对于一个二维矩阵，如果同行或者同列存在石头，那么就说明这是连通的
 * 删除掉同行或者同列的石头之后，剩下的石头数目=总的石头数目-连通分量
 * 还需要解决的一个问题是如果区分同行或者同列，这里面使用到了一个映射，就是把横坐标或者纵坐标
 * 加上超出给定10000范围的值（不过在定义的时候，注意数组范围）
*/

int find(int *fa, int x) {
    return fa[x] = (fa[x] == x ? x : find(fa, fa[x]));
}

int removeStones(int** stones, int stonesSize, int* stonesColSize){
    int fa[20005], hash[20005];
    for (int i = 0; i < 20005; i++) {
        fa[i] = i;
        hash[i] = -1;
    }
    int line = 0, row = 0, cnt = 0;
    for (int i = 0; i < stonesSize; i++) {
        line = find(fa, stones[i][0]);
        row = find(fa, stones[i][1] + 10001);
        if (line != row) {
            fa[line] = row;
        }
    }
    for (int i = 0; i < stonesSize; i++) {
        line = find(fa, stones[i][0]);
        if (hash[line] == -1) {
            cnt++;
            hash[line] = line;
        }
    }
    return stonesSize - cnt;
}