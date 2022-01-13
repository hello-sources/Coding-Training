int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize){
    int ans = 0;
    qsort(seats, seatsSize, sizeof(int), cmp);
    qsort(students, studentsSize, sizeof(int), cmp);
    for (int i = 0; i < seatsSize; i++) {
        ans += abs(students[i] - seats[i]);
    }
    return ans;
}