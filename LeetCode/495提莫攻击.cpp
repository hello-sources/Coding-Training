int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    int cnt = 0, dur = 0;
    for (int i = 0; i < timeSeriesSize; i++) {
        if (timeSeries[i] >= dur) {
            cnt += duration;
        } else {
            cnt += timeSeries[i] + duration - dur;
        }
        dur = timeSeries[i] + duration;
    }
    return cnt;
}