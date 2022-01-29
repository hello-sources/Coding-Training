int cmp(const void *a, const void *b) {
    int *pa = *(int **)a;
    int *pb = *(int **)b;
    return pa[0] == pb[0] ? (pa[1] - pb[1]) : (pb[0] - pa[0]);
}

int numberOfWeakCharacters(int** properties, int propertiesSize, int* propertiesColSize){
    qsort(properties, propertiesSize, sizeof(int *), cmp);
    int ans = 0, max = 0;
    for (int i = 0; i < propertiesSize; i++) {
        if (properties[i][1] < max) ans++;
        else max = fmax(max, properties[i][1]);
    }
    return ans;
}