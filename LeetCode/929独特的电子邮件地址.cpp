//转换电子邮件格式的时候，在当前字符串中直接进行操作，@符号前面的不用管
//对于.号直接跳过，然后对于+号，那么可以跳出循环了，值得注意的时候循环的条件是不等于@符号
//因为@符号之后的不用管
#define MAX_N 105
char *get_correct_email(char *s) {
    int i = 0, cnt = 0;
    for (; s[i] != '@'; i++) {
        if (s[i] == '.') continue;
        else if (s[i] == '+') break;
        else {
            s[cnt++] = s[i];
        }
    }
    while (s[i] != '@') i++;
    while (s[i] != '\0') s[cnt++] = s[i++];
    s[cnt] = '\0';
    return s;
}

int numUniqueEmails(char ** emails, int emailsSize){
    int cnt = 0;
    char temp[10] = {"test"};
    for (int i = 0; i < emailsSize; i++) {
        emails[i] = get_correct_email(emails[i]);
    }
    for (int i = 0; i < emailsSize; i++) {
        for (int j = 0; j < emailsSize; j++) {
            if (i == j) continue;
            if (emails[j] != temp && strcmp(emails[i], emails[j]) == 0) cnt++, emails[j] = temp;
        }
    }
    return emailsSize - cnt;
}

/********************独特的电子邮件地址******************/
class Solution {
public:
    int numUniqueEmails(vector<string> &emails) {
        unordered_set<string> emailSet;
        for (auto &email: emails) {
            string local;
            for (char c: email) {
                if (c == '+' || c == '@') {
                    break;
                }
                if (c != '.') {
                    local += c;
                }
            }
            emailSet.emplace(local + email.substr(email.find('@')));
        }
        return emailSet.size();
    }
};