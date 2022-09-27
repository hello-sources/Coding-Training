class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        int nums1[] = new int[128];
        int nums2[] = new int[128];
        char[] chs1 = s1.toCharArray();
        char[] chs2 = s2.toCharArray();
        for (int i = 0; i < chs1.length; i++) {
            nums1[chs1[i]]++;
        }
        for (int i = 0; i < chs2.length; i++) {
            nums2[chs2[i]]++;
        }
        for (int i = 0; i < 128; i++) {
            if (nums2[i] != nums1[i]) return false;
        }
        return true;
    }
}

/**
 * 使用Array.sort对数组进行排序
 */
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        int nums1[] = new int[128];
        int nums2[] = new int[128];
        char[] chs1 = s1.toCharArray();
        char[] chs2 = s2.toCharArray();
        Arrays.sort(chs1);
        Arrays.sort(chs2);
        for (int i = 0, j = 0; i < chs1.length && j < chs2.length; i++, j++) {
            if (chs1[i] != chs2[j]) return false;
        }
        if (chs1.length != chs2.length) return false;
        return true;
    }
}