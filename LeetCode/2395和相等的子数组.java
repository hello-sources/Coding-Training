/**
 * HashSet 无序的，插入/删除/查找时间复杂度O(1)
 * TreeSet 基于红黑树的有序的，插入/删除/查找时间复杂度O(logN)
 * 判断Set中是否有对应元素方法使用  contains() 方法
 */
class Solution {
    public boolean findSubarrays(int[] nums) {
        if (nums.length < 3) return false;
        Set<Integer> set = new HashSet<>();
        for (int i = 1; i < nums.length; i++) {
            if (set.contains(nums[i - 1] + nums[i])) return true;
            else set.add(nums[i - 1] + nums[i]);
        }
        return false;
    }
}