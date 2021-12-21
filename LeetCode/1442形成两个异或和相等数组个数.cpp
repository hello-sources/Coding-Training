/**
 * Si⊕Sj=arr[i]⊕⋯⊕arr[j−1]
 * 所以从i到j区间异或和可以表示为Si⊕Sj+1
 * 而题中a = Si⊕Sj, b = Sj⊕Sk+1
 * 令a == b,则只需要Si == Sk+1
 * **/

int countTriplets(int* arr, int arrSize){
    int cnt = 0;
    int sum[arrSize + 5];
    sum[0] = 0;
    for (int i = 0; i < arrSize; i++) {
        sum[i + 1] = sum[i] ^ arr[i];
    }
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            for (int k = j; k < arrSize; k++) {
                if (sum[i] == sum[k + 1]) cnt++;
            }
        }
    }
    return cnt;
}