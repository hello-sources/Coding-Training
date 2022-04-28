class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 == 2) return false;
            else return checkPowersOfThree(n / 3);
        }
        return true;
    }
};