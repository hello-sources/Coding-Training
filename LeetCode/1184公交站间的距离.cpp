int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < distanceSize; i++) {
        cnt0 += distance[i];
    }
    for (int i = fmin(start, destination); i < fmax(start, destination); i++) {
        cnt1 += distance[i];
    }
    return fmin(cnt0 - cnt1, cnt1);
}