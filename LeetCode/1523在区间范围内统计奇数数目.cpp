// int countOdds(int low, int high){
//     int cnt = 0;
//     for (int i = low; i <= high; i++) {
//         if (i % 2 == 1) cnt++;
//     }
//     return cnt;
// }
int countOdds(int low, int high) {
    return (high + 1) / 2 - low / 2;
}