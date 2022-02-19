int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

double average(int* salary, int salarySize){
    qsort(salary, salarySize, sizeof(int), cmp);
    double sum = 0;
    for (int i = 1; i < salarySize - 1; i++) {
        sum += salary[i];
    }
    return sum / (salarySize - 2);
}