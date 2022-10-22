/**
 * 1、Java进行声明HashMap的时候最好使用包装类
 * 2、给map里面的数组添加数据的时候使用到map.put而不是直接用等号获取
 * 3、获取数据有两个，一个是get(), 一个是getOrDefault表示如果没有就给个默认值
 * 4、删除就是remove()
 */
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