//使用双指针，分别从字符串的首位两端进行遍历判断是否为回文串
//使用递归方法判断给定首位区间内字符串是否为回文串即可

bool judge(char *s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}


bool validPalindrome(char * s){
    int l = 0, r = strlen(s) - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return judge(s, l, r - 1) || judge(s, l + 1, r);
        }
        l++;
        r--;
    }
    return true;
}