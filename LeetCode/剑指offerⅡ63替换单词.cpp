class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans = "";
        string temp = "";
        unordered_set<string> u_set;
        for (auto x : dictionary) u_set.insert(x);
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                ans += temp;
                ans += " ";
                temp.clear();
                continue;
            }
            if (i == sentence.size() - 1) {
                temp += sentence[i];
                ans += temp;
                ans += " ";
                continue;
            }
            temp += sentence[i];
            if (u_set.find(temp) != u_set.end()) {
                ans += temp;
                ans += " ";
                while (i < sentence.size() && sentence[i] != ' ') i++;
                temp.clear();
            }
        }
        ans.pop_back();
        return ans;
    }
};