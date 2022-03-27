bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int cnt = 0;
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 1) cnt += 0;
        else if ((i == 0 || flowerbed[i - 1] == 0) && (i == flowerbedSize - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            cnt++;
        }
    }
    if (cnt >= n) return true;
    return false;
}