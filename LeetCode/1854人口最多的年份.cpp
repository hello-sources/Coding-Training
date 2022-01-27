int maximumPopulation(int** logs, int logsSize, int* logsColSize){
    int cnt = 0, max = 0;
    int year[2055] = {0};
    for (int i = 0; i < logsSize; i++) {
        for (int j = logs[i][0]; j <= logs[i][1] - 1; j++) {
            year[j] += 1;
            max = fmax(max, year[j]);
        }
    }
    for (int i = 1950; i <= 2050; i++) {
        if (year[i] == max) return i;
    }
    return -1;
}