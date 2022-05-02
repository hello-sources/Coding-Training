class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int len = expression.size();
        if (len == 1 || len == 2) {
            ans.emplace_back(stoi(expression));
            return ans;
        }
        for (int i = 0; i < len; i++) {
            char ch = expression[i];
            if (ch == '+' || ch == '*' || ch == '-') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (auto &l : left) {
                    for (auto &r : right) {
                        switch (ch) {
                            case '+' : ans.emplace_back(l + r); break;
                            case '*' : ans.emplace_back(l * r); break;
                            case '-' : ans.emplace_back(l - r); break;
                        }
                    }
                } 
            }
        }
        return ans;
    }
};