// Arrays.equals表示对比两个数组是否相等
// 滑动窗口
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int lens = s.length(), lenp = p.length();
        if (lens < lenp) return new ArrayList<Integer>();
        List<Integer> ans = new ArrayList<Integer>();
        int[] chsp = new int[26];
        int[] chss = new int[26];
        for (int i = 0; i < lenp; i++) {
            ++chss[s.charAt(i) - 'a'];
            ++chsp[p.charAt(i) - 'a'];
        }
        if (Arrays.equals(chss, chsp)) {
            ans.add(0);
        }
        for (int i = lenp; i < lens; i++) {
            --chss[s.charAt(i - lenp) - 'a'];
            ++chss[s.charAt(i) - 'a'];
            if (Arrays.equals(chss, chsp)) {
                ans.add(i - lenp + 1);
            }
        }
        return ans;
    }
}