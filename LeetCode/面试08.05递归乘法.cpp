class Solution {
public:
    int multiply(int A, int B) {
        int temp = A;
        while (--B) {
            A += temp;
        }
        return A;
    }
};