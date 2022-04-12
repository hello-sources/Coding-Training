class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);
        for (int i = 0; i < str.length(); i++) {
            for (int j = i; j < str.length(); j++) {
                if ((str[i] - str[j]) % 2 == 0 && str[i] < str[j]) {
                    swap(str[i], str[j]);
                }
            }
        }
        return stoi(str);
    }
};