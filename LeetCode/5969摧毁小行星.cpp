int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize){
    qsort(asteroids, asteroidsSize, sizeof(int), cmp);
    long long cnt = mass;
    for (int i = 0; i < asteroidsSize; i++) {
        if (cnt >= asteroids[i]) cnt += asteroids[i];
        else return false;
    }
    return true;
}