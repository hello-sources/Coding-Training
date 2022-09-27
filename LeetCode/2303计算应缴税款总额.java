class Solution {
    public double calculateTax(int[][] brackets, int income) {
        if (income == 0) return 0;
        double ans = 0;
        if (income <= brackets[0][0]) ans += (double)income * brackets[0][1] / 100;
        if (income > brackets[0][0]) ans += (double)brackets[0][0] * brackets[0][1] / 100;
        for (int i = 1; i < brackets.length; i++) {
            if (income >= brackets[i][0]) {
                ans += (double)(brackets[i][0] - brackets[i - 1][0]) * brackets[i][1] / 100;
            } 
            else if (income < brackets[i][0] && income > brackets[i - 1][0]) {
                ans += (double)(income - brackets[i - 1][0]) * brackets[i][1] / 100;
            } 
        }
        return ans;
    }
}