#define MAX_SIZE 10000
bool help(char input) {
    if ((input == 'a') || (input == 'e') || (input == 'i') || (input == 'o') || (input == 'u') ||
    (input == 'A') || (input == 'E') || (input == 'I') || (input == 'O') || (input == 'U')) {
        return true;
    }
    return false;
}

void move(char* p, int size) {
    int i = 0;
    char tmp = p[0];
    while (i < size - 1) {
        p[i] = p[i + 1];
        i++;
    }
    p[size - 1] = tmp;
}

void add(char* p, int* index, int num) {
    while (num > 0) {
        p[(*index)++] = 'a';
        num--;
    }
}
char * toGoatLatin(char * S){
    char* res = (char*)malloc(MAX_SIZE);
    if (res == NULL) return NULL;
    memset(res, 0, MAX_SIZE);
    int index = 0, num = 1;
    char* p = strtok(S, " ");
    while (p != NULL) {
        // 对每一个分隔的单词进行处理，并填到结果中
        int len = strlen(p);
        // 1.判断元音
        if (!help(p[0])) {
            move(p, len); // 辅音处理
        }
        strncpy((res + index), p, len);
        index += len;
        // 2.添加ma
        res[index++] = 'm';
        res[index++] = 'a';
        // 3.添加多个a
        add((res), &index, num);
        
        // 补充空格
        res[index++] = ' ';
        p = strtok(NULL, " ");
        num++;
    }
    if (index > 0) {
        index--;
        res[index] = '\0';
    }
    return res;
}




/****************C++***************/
class Solution {
public:
    bool judge(char ch) {
        string temp = "aeiouAEIOU";
        int flag = false;
        for (auto c : temp) {
            if (ch == c) {
                flag = true;
                break;
            }
        }
        return flag;
    }

    string toGoatLatin(string sentence) {
        string ans;
        int cnt = count(sentence.begin(), sentence.end(), ' ');
        vector<string> stor(cnt + 1);
        int count = 0;
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                count++;
                continue;
            }
            stor[count].push_back(sentence[i]);
        }
        for (int i = 0; i < stor.size(); i++) {
            if (judge(stor[i][0])) stor[i] += "ma";
            else {
                char ch = stor[i][0];
                stor[i] = stor[i].substr(1);
                stor[i] += ch;
                stor[i] += "ma";
            }
            for (int j = 0; j <= i; j++) stor[i] += "a";
        }
        for (int i = 0; i < stor.size(); i++) {
            ans += stor[i];
            if (i < stor.size() - 1) ans += " ";
        }
        return ans;
    }
};