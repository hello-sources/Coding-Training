/************************大佬的手撕倍增法后缀数组，没看懂****************************/
#define N 250000
int L, K;
int height[N], rank[N], pos[N];

int cmp(const void* a, const void* b) {
    int aa = *(int*)a, bb = *(int*)b;
    if (rank[aa] != rank[bb])return rank[aa] - rank[bb];
    else {
        int raa = aa + K < L ? rank[aa + K] : -1;
        int rbb = bb + K < L ? rank[bb + K] : -1;
        return raa - rbb;
    }
}

void bulid(int* A) {
    int i, j, M[N];
    for (i = 0; i < L; i++) { pos[i] = i; rank[i] = A[i]; }
    for (K = 1; K < L; K <<= 1) {
        qsort(pos, L, sizeof(int), cmp);
        M[pos[0]] = 0;
        for (i = 1; i < L; i++) {
            M[pos[i]] = M[pos[i - 1]] + +(cmp((void*)&pos[i - 1], (void*)&pos[i]) < 0);
        }
        for (i = 0; i < L; i++)rank[i] = M[i];
    }
}

void getH(int* A) {
    int i, j, k=0; height[0] = 0;
    for (i = 0; i < L; i++)rank[pos[i]] = i;
    for (i = 0; i < L; i++) {
        if (rank[i] == 0)continue;
        if (k)k--;
        j = pos[rank[i] - 1];
        while (i + k < L && A[j + k] == A[i + k])k++;
        height[rank[i]] = k;
    }
}

char * longestDupSubstring(char * s){
    L=strlen(s);      int i,j,k,A[L+1],right=0;     
    char *res=(char *)malloc(L+1); 
    for(i=0;i<L;i++){
        A[i]=s[i]-'a';
    } bulid(A); getH(A);

    int max = 0, maxp = 0;
    for (i = 0; i < L; i++) {
        if (height[i] > max) { maxp = i; max = height[i]; }
    } if (max == 0)return "";
    for (i = pos[maxp]; right < max; i++, right++) {
        res[right] = s[i]; 
    }res[right]=0;
    return res;
}

/*********************大佬的以时间换空间*************************/
char * longestDupSubstring(char * s){
    int len = strlen(s), maxSubLen = 0, SubLen = 1;
    char* pChar = NULL;
    char* pResult = NULL;
    char* sBak = (char *)malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len - 1; i++) {
        SubLen = maxSubLen > 1 ? maxSubLen : 1;
        while (i + SubLen < len) {
            // sBak保存被搜索字符串
            strcpy(sBak, s + i);  
            sBak[SubLen] = '\0';
            pChar = strstr(s + i + 1, sBak); // 从下一个字符开始检索是否存在重复子串
            if (pChar == NULL) break;
            if (pChar != NULL && maxSubLen < SubLen) {
                maxSubLen = SubLen; 
                pResult = pChar;
            } 
            SubLen++;    
        }
    } 
    if (maxSubLen == 0) {
        return "";
    }
    strcpy(sBak, pResult);
    sBak[maxSubLen] = '\0';
    return sBak;
}