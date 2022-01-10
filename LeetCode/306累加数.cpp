char *add(char *s, int start1, int end1, int start2, int end2) {
    char *third = (char *)malloc(sizeof(char) * (strlen(s) + 5));
    int size = 0, car = 0, cur = 0;
    while (start1 <= end1 || start2 <= end2 || car != 0) {
        cur = car;
        if (start1 <= end1) {
            cur += s[end1] - '0';
            end1--;
        }
        if (start2 <= end2) {
            cur += s[end2] - '0';
            end2--;
        }
        car = cur / 10;
        cur %= 10;
        third[size++] = cur + '0';
    }
    int l = 0, r = size - 1;
    while (l < r) {
        char c = third[l];
        third[l] = third[r];
        third[r] = c;
        l++;
        r--;
    }
    third[size] = '\0';
    return third;
}

bool valid(int start2, int end2, char *num) {
    int len = strlen(num);
    int start1 = 0, end1 = start2 - 1;
    while (end2 <= len - 1) {
        char *third = add(num, start1, end1, start2, end2);
        int start3 = end2 + 1, end3 = end2 + strlen(third);
        if (end3 >= len || strncmp(num + start3, third, end3 - start3 + 1)) {
            free(third);
            break;
        }
        free(third);
        if (end3 == len - 1) return true;
        start1 = start2;
        end1 = end2;
        start2 = start3;
        end2 = end3;
    }
    return false;
}

bool isAdditiveNumber(char * num){
    int len = strlen(num);
    for (int start2 = 1; start2 < len - 1; start2++) {
        if (num[0] == '0' && start2 != 1) break;
        for (int end2 = start2; end2 < len - 1; end2++) {
            if (num[start2] == '0' && start2 != end2) break;
            if (valid(start2, end2, num)) return true;
        }
    }
    return false;
}