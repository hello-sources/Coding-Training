class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> map = new HashMap<>();
        int ans = 0;
        int left = 0;
        for (int i = 0; i < fruits.length; i++) {
            map.put(fruits[i], map.getOrDefault(fruits[i], 0) + 1);
            if (map.size() > 2) {
                int y = fruits[left];
                map.put(y, map.get(y) - 1);
                if (map.get(y) == 0) {
                    map.remove(y);
                }
                left++;
            }
            ans = Math.max(ans, i - left + 1);
        }
        return ans;
    }
}