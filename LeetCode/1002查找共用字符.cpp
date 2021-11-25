/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//哈希表，分别存储对应字符出现的次数以及重复出现的次数
char ** commonChars(char ** words, int wordsSize, int* returnSize){
    int hash[26] = {0};
    int minhash[26] = {0};
    char **ret = (char **)malloc(sizeof(char *) * 101);
    int cal = 0;
    while (words[0][cal]) {
        minhash[words[0][cal] - 'a']++;
        cal++;
    }
    for (int i = 1; i < wordsSize; i++) {
        int j = 0;
        memset(hash, 0, sizeof(hash));
        while (words[i][j]) {
            hash[words[i][j] - 'a']++;
            j++;
        }
        for (int k = 0; k < 26; k++) {
            if (hash[k] < minhash[k]) minhash[k] = hash[k];
        }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (minhash[i]) {
            while (minhash[i]) {
                ret[count] = (char *)malloc(sizeof(char) * 2);
                ret[count][0] = i + 'a';
                ret[count][1] = 0;
                count++;
                minhash[i]--;
            }
        }
    }
    *returnSize = count;
    return ret;
}