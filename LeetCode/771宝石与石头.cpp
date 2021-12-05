int numJewelsInStones(char * jewels, char * stones){
    int cnt = 0, len1 = strlen(jewels), len2 = strlen(stones);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (jewels[i] == stones[j]) cnt++;
        }
    }
    return cnt;
}