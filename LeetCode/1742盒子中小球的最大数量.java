class Solution {
    public int countBalls(int lowLimit, int highLimit) {
        Integer[] ans = new Integer[100];
        Arrays.fill(ans, 0);
        for (int i = lowLimit; i <= highLimit; i++) {
            ans[calcNum(i)]++;
        }
        Arrays.sort(ans, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return b - a;
            }
        });
        //也可以写成
        // Arrays.sort(ans, (a, b) -> (b - a));
        // Arrays.sort(ans, (a, b) -> Integer.compare(b, a));
        return ans[0];
    }

    public int calcNum(int num) {
        int ans = 0;
        while (num > 0) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }
}