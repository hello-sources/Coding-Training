char slowestKey(int* releaseTimes, int releaseTimesSize, char * keysPressed){
    char ans = keysPressed[0];
    int res = releaseTimes[0];
    for (int i = 1; i < releaseTimesSize; i++) {
        if (res < releaseTimes[i] - releaseTimes[i - 1]) {
            res = releaseTimes[i] - releaseTimes[i - 1];
            ans = keysPressed[i];
        } else if ((res == releaseTimes[i] - releaseTimes[i - 1]) && (ans < keysPressed[i])) {
            res = releaseTimes[i] - releaseTimes[i - 1];
            ans = keysPressed[i];
        }
    }
    return ans;
}