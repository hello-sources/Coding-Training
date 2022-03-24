int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

bool hasGroupsSizeX(int* deck, int deckSize){
    int num[10005] = {0}, max = 0, ans = 0;
    if (deckSize == 1) return false;
    for (int i = 0; i < deckSize; i++) {
        num[deck[i]]++;
        max = fmax(max, deck[i]);
    }
    for (int i = 0; i <= max; i++) {
        if (num[i]) ans = gcd(num[i], ans);
    }
    return ans >= 2;
}