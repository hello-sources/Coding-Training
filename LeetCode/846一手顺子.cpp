int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool isNStraightHand(int* hand, int handSize, int groupSize){
    qsort(hand, handSize, sizeof(int), cmp);
    if (handSize % groupSize != 0) return false;
    for (int i = 0; i < handSize; i++) {
        if (hand[i] >= 0) {
            int pre = hand[i], cnt = 0;
            for (int j = i; j < handSize && cnt < groupSize; j++) {
                if (hand[j] != pre) continue;
                pre++;
                cnt++;
                hand[j] = -1;
            }
            if (cnt < groupSize) return false;
        }
    }
    return true;
}