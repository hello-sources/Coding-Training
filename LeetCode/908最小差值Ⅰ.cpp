int smallestRangeI(int* A, int ASize, int K){
    int min=A[0];
    int max=A[0];
    for(int i=0;i<ASize;i++){
        min = fmin(min, A[i]);
        max = fmax(max, A[i]);
    }
    int differ=max-min;
    if(2*K>=differ)return 0;
    else return differ-2*K;
}