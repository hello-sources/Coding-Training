class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans, temp;
        ans.emplace_back(words[0]);
        for (int  i = 0; i < words.size(); i++) {
            temp.emplace_back(words[i]);
            sort(temp[i].begin(), temp[i].end());
        }
        
        for (int i = 1; i < words.size(); i++) {
            if (temp[i - 1] != temp[i]) ans.emplace_back(words[i]);
        }

        return ans;
    }
};