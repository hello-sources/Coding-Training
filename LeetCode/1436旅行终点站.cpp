//只要找到不在出发点出现的站点就行了
char * destCity(char *** paths, int pathsSize, int* pathsColSize){
    int cnt;
    for (int i = 0; i < pathsSize; i++) {
        cnt = 0;
        for (int j = 0; j < pathsSize; j++) {
            if (strcmp(paths[i][1], paths[j][0]) == 0) cnt++;
        }
        if (cnt == 0) {
            return paths[i][1];
        }
    }
    return -1;
}