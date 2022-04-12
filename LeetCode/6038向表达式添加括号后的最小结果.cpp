class Solution {
public:
    string minimizeResult(string expression) {
        int ind = 0;
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] != '+') continue;
            ind = i;
            break;
        }
        string str1 = expression.substr(0, ind);
        string str2 = expression.substr(ind + 1, expression.length() - 1);
        int min_temp = INT_MAX, lind = 0, rind = 0;
        for (int i = 0; i < str1.length(); i++) {
            int l = 1, r = 1;
            for (int j = str2.length() - 1; j >= 0; j--) {
                if (i != 0) l = atoi(str1.substr(0, i).c_str());
                int num1 = atoi(str1.substr(i, str1.length()).c_str());
                int num2 = atoi(str2.substr(0, j + 1).c_str());
                if (j != str2.size() - 1) r = atoi(str2.substr(j + 1, str2.length()).c_str());
                int temp = l * (num1 + num2) * r;
                if (temp < min_temp) {
                    min_temp = temp;
                    lind = i;
                    rind = j;
                }
            }
        }
        string res;
        for (int i = 0; i < expression.length(); i++) {
            if (i == lind) res += '(';
            res += expression[i];
            if (i == ind + rind + 1) res += ')';
        }
        return res;
    }
};