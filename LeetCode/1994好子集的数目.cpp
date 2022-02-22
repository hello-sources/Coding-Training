const int PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; 
const int NUM_MAX = 30;
const int MOD = 1000000007;

int numberOfGoodSubsets(int* nums, int numsSize){
    int primesSize = sizeof(PRIMES) / sizeof(int);
    int * freq = (int *)malloc(sizeof(int) * (NUM_MAX + 1));
    memset(freq, 0, sizeof(int) * (NUM_MAX + 1));
    for (int i = 0; i < numsSize; i++) {
        ++freq[nums[i]];
    }
    int * f = (int *)malloc(sizeof(int) * (1 << primesSize));
    memset(f, 0, sizeof(int) * (1 << primesSize));
    f[0] = 1;
    for (int i = 0; i < freq[1]; ++i) {
        f[0] = f[0] * 2 % MOD;
    }
    
    for (int i = 2; i <= NUM_MAX; ++i) {
        if (!freq[i]) {
            continue;
        }
        
        // 检查 i 的每个质因数是否均不超过 1 个
        int subset = 0, x = i;
        bool check = true;
        for (int j = 0; j < primesSize; ++j) {
            int prime = PRIMES[j];
            if (x % (prime * prime) == 0) {
                check = false;
                break;
            }
            if (x % prime == 0) {
                subset |= (1 << j);
            }
        }
        if (!check) {
            continue;
        }

        // 动态规划
        for (int mask = (1 << primesSize) - 1; mask > 0; --mask) {
            if ((mask & subset) == subset) {
                f[mask] = (f[mask] + (long)(f[mask ^ subset]) * freq[i]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int mask = 1, mask_max = (1 << primesSize); mask < mask_max; ++mask) {
        ans = (ans + f[mask]) % MOD;
    }
    free(freq);
    free(f);
    return ans;
}