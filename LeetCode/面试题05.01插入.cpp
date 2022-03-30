int insertBits(int N, int M, int i, int j){
    for (int s = i; s <= j; s++) {
        N &= ~((unsigned int)1 << s);
    }
    N |= (M << i);
    return N;
}