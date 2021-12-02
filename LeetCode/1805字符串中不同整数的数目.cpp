//不对劲的代码，只通过83组数据，就差剩下俩不行
int numDifferentIntegers(char * word){
    char nums[1005][1005];
    int cnt = 0, now = 0, len = strlen(word);
    for (int i = 0; i < len + 1; i++) {
        if (now != 0) {
            if (word[i] >= '0' && word[i] <= '9') {
                nums[cnt][now++] = word[i];
            } else {
                nums[cnt][now] = '\0';
                cnt++;
                now = 0;
            }
        } else {
            if (word[i] >= '1' && word[i] <= '9') {
                nums[cnt][now++] = word[i];
            } else {
                if (i > 1 && word[i - 1] == '0' && (word[i] < '0' || word[i] > '9')) {
                    nums[cnt][now++] = '0';
                    nums[cnt][now] = '\0';
                    cnt++;
                    now = 0;
                }
            }
        }
    }
    int ans = cnt;
    for (int i = 0; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (strcmp(nums[i], nums[j]) == 0) {
                ans--;
                break;
            }
        }
    }
    return ans;
}

//暴力解法
bool is_num(char c) {
    return c <= '9' && c >= '0';
}

int numDifferentIntegers(char * word){
    int res[500][3] = {0};
    int fast = 0, slow = 0, cnt = 0, len = strlen(word);
    while (fast < len) {
        if (is_num(word[fast])) {
            slow = fast;
            while (fast < len && is_num(word[fast])) {
                fast++;
            }
            res[cnt][0] = slow;
            res[cnt++][1] = fast - 1;
        }
        fast++;
    }
    for (int i = 0; i < cnt; i++) {
        while (word[res[i][0]] == '0' && res[i][0] < res[i][1]) res[i][0]++;
    }
    int ans = cnt;
    for (int i = 0; i < cnt - 1; i++) {
        if (!res[i][2]) {
            int temp1 = res[i][1] - res[i][0];
            for (int j = i + 1; j < cnt; j++) {
                int temp2 = res[j][1] - res[j][0];
                if (temp1 == temp2 && !strncmp(&word[res[i][0]],&word[res[j][0]], temp1 + 1)) {
                    res[j][2] = 1;
                    ans--;
                }
            }
        }
    }
    return ans;
}