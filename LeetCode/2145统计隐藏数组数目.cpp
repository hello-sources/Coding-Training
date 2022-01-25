// int numberOfArrays(int* differences, int differencesSize, int lower, int upper){
//     if (differencesSize == 0) return 0;
//     long *sum = (long *)malloc(sizeof(long) * (differencesSize + 5));
//     sum[0] = differences[0];
//     for (int i = 1; i < differencesSize; i++) {
//         sum[i] = sum[i - 1] + differences[i]; 
//     }
//     int left = lower, right = upper;
//     for (int i = 0; i < differencesSize; i++) {
//         left = fmax(left, lower - sum[i]);
//         right = fmin(right, upper - sum[i]);   
//     }
//     if (left > right) return 0;
//     return right - left + 1;
// }
int numberOfArrays(int* differences, int differencesSize, int lower, int upper){
    long num = 0, minVal = 0, maxVal = 0;
    for (int i = 0; i < differencesSize; i++) {
        num += differences[i];
        minVal = fmin(minVal, num);
        maxVal = fmax(maxVal, num);
    }
    return fmax(0, (upper - lower) - (maxVal - minVal) + 1);
}