/**
 * 利用排列思想，维护一个为s1长度的滑动窗口
 * 首先记录下对应s1串的字符个数，采用减去 'a'来计数
 * 如果对应都相等，则说明s1的一个排列在s2串中
 * **/

bool cmp(int *num1, int *num2) {
    for (int i = 0; i < 26; i++) {
        if (num1[i] != num2[i]) return false;
    }
    return true;
}

bool checkInclusion(char * s1, char * s2){
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 > len2) return false;
    int cnt1[26], cnt2[26];
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 0; i < len1; i++) {
        cnt1[s1[i] - 'a']++;
        cnt2[s2[i] - 'a']++;
    }
    if (cmp(cnt1, cnt2)) return true;
    for (int i = len1; i < len2; i++) {
        cnt2[s2[i] - 'a']++;
        cnt2[s2[i - len1] - 'a']--;
        if (cmp(cnt1, cnt2)) return true;
    }
    return false;
}