// 可以将list, set转换为流数据进行处理，从而转换为int类型的数组
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new HashMap<>();
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < nums1.length; i++) {
            map.put(nums1[i], map.getOrDefault(nums1[i], 1));
        } 
        for (int i = 0; i < nums2.length; i++) {
            if (map.get(nums2[i]) != null) {
                set.add(nums2[i]);
            }
        }
        // int[] ans = list.stream().mapToInt(i->i).toArray();
        int[] ans = set.stream().mapToInt(i->i).toArray();
        return ans;
    }
}