class Solution {
    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>();
        while (n != 1 && !set.contains(n)) {
            set.add(n);
            n = calc(n);
        }
        return n == 1;
    }

    public int calc(int num) {
        int sum = 0;
        while (num > 0) {
            int temp = num % 10;
            sum += temp * temp;
            num /= 10;
        }
        return sum;
    }
}