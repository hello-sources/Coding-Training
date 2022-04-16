class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> vec(5, 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 3; j >= 0; j--) {
                vec[j] += vec[j + 1];
            }
        }
        return accumulate(vec.begin(), vec.end(), 0);
    }
};