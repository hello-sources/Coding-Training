class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int ans = 0, ind = s.length - 1;
        for (int i = g.length - 1; i >= 0; i--) {
            if (ind >= 0 && s[ind] >= g[i]) {
                ind--;
                ans++;
            }
        }
        return ans;
    }
}