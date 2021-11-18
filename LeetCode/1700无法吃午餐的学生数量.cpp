int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize){
    int cnt = 0;
    for (int i =0; i < sandwichesSize; i++) {
        for (int j = 0; j < studentsSize; j++) {
            if (cnt >= studentsSize) break;
            if (students[j] == sandwiches[cnt]) {
                students[j] = -1;
                cnt++;
            }
        }
    }
    return studentsSize - cnt;
}