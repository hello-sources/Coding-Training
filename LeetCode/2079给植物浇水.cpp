int wateringPlants(int* plants, int plantsSize, int capacity){
    int ans = 0, temp = capacity;
    for (int i = 0; i < plantsSize; i++) {
        if (temp >= plants[i]) {
            temp -= plants[i];
            ans++;
        } else {
            temp = capacity - plants[i];
            ans += i * 2 + 1;
        }
    }
    return ans;
}