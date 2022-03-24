/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* masterMind(char* solution, char* guess, int* returnSize){
    int hash1[26] = {0}, hash2[26] = {0};
    int*ans = (int*)calloc(2, sizeof(int));
    
    *returnSize = 2;
    for(int i = 0; i < 4; i++)
    {
        if(solution[i] == guess[i])
            ans[0]++;
        else
        {
            hash1[solution[i] - 'A']++;
            hash2[guess[i] - 'A']++;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        ans[1] += fmin(hash1[i], hash2[i]);
    }
    return ans;
}