bool isAlienSorted(char ** words, int wordsSize, char * order){
    int hash[26] = {0};
    for (int i = 0; i < strlen(order); i++) {
        hash[order[i] - 'a'] = i;
    }
    for (int i = 0; i < wordsSize - 1; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            if (words[i][j] == '\0' || words[i + 1][j] == '\0') return false;
            if (words[i][j] == words[i + 1][j]) continue;
            else if (hash[words[i][j] - 'a'] > hash[words[i + 1][j] - 'a']) return false;
            else if (hash[words[i][j] - 'a'] < hash[words[i + 1][j] - 'a']) break;
        }
    }
    return true;
}

/***********************unordered_map*********************/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> u_map;
        for (int i = 0; i < order.size(); i++) u_map[order[i]] = i + 1;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                words[i][j] = u_map[words[i][j]];
            }
        }
        for (int i = 1; i < words.size(); i++) {
            if (words[i] < words[i - 1]) return false;
        }
        return true;
    }
};