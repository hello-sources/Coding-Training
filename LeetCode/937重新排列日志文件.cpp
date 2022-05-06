/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int cmp(const void *a, const void *b) {
//     int i = 0, j = 0;
//     char *s1 = *(char **)a;
//     char *s2 = *(char **)b;
//     while (*(s1 + i++) != ' ');
//     while (*(s2 + j++) != ' ');
//     if (*(s1 + i) <= '9' && *(s1 + i) >= '0' && *(s2 + j) <= '9' && *(s2 + j) >= '0') return 0;
//     if (*(s1 + i) <= 'z' && *(s1 + i) >= 'a' && *(s2 + j) <= 'z' & *(s2 + j) >= 'a') {
//         for ( ; *(s1 + i) != '\0' && *(s2 + j) != '\0' && *(s1 + i) == *(s2 + j); i++, j++);
//         if (i == j && *(s1 + i) == *(s2 + j)) {
//             i = j = 0;
//             for ( ; *(s1 + i) != '\0' && *(s2 + j) != '\0' && *(s1 + i) == *(s2 + j); i++, j++);
//         }
//         return *(s1 + i) - *(s2 + j);
//     }
//     if (*(s1 + i) >= 'a' && *(s1 + i) <= 'z') return -1;
//     return 1;
// }

// char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
//     *returnSize = logsSize;
//     qsort(logs, logsSize, sizeof(*(logs + 0)), cmp);
//     return logs;
// }
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc(const void *a, const void *b) {
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;
    int result;
    while(*s1 != ' ' && *s1 != '\0') s1++;
    while(*s2 != ' ' && *s2 != '\0') s2++;
    result = strcmp(s1, s2);
    if (result != 0) return result;
    return strcmp(*(char **)a, *(char **)b);
}
char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
    char **ret_log = (char **)malloc(sizeof(char *) * logsSize);
    char *log_index = NULL;
    int nums_i = logsSize - 1, letter_i = 0;
    for (int i = logsSize - 1; i >= 0; i--) {
        log_index = logs[i];
        while (*log_index != ' ' && *log_index != '\0') {
            log_index++;
        }
        if (*(log_index + 1) >= '0' && *(log_index + 1) <= '9') {
            ret_log[nums_i--] = logs[i];
        } else {
            ret_log[letter_i++] = logs[i];
        }
    }
    for (int i = 0; i < logsSize; i++) {
        printf("%s\n", ret_log[i]);
    }

    qsort(ret_log, letter_i, sizeof(char *), cmpfunc);
    *returnSize = logsSize;
    return ret_log;
}

/**********************************C++**************************/
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [&](const string &log1, const string &log2){
            int pos1 = log1.find_first_of(" ");
            int pos2 = log2.find_first_of(" ");
            bool isDigit1 = isdigit(log1[pos1 + 1]);
            bool isDigit2 = isdigit(log2[pos2 + 1]);
            if (isDigit1 && isDigit2) return false;
            if (!isDigit1 && !isDigit2) {
                string s1 = log1.substr(pos1);
                string s2 = log2.substr(pos2);
                if (s1 != s2) return s1 < s2;
                return log1 < log2;
            }
            return isDigit1 ? false : true;
        });
        return logs;
    }
};