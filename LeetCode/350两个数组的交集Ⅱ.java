class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            return intersect(nums2, nums1);
        }
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums1.length; i++) {
            map.put(nums1[i], map.getOrDefault(nums1[i], 0) + 1);
        } 
        for (int i = 0; i < nums2.length; i++) {
            int count = map.getOrDefault(nums2[i], 0);
            if (count > 0) {
                list.add(nums2[i]);
                count--;
                if (count > 0) {
                    map.put(nums2[i], count);
                } else {
                    map.remove(nums2[i]);
                }
            }
        }
        int[] ans = list.stream().mapToInt(i->i).toArray();
        return ans;
    }
}