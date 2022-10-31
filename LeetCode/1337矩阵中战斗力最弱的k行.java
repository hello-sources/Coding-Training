class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int[][] cnt_solder = new int[mat.length][2];
        for (int i = 0; i < mat.length; i++) {
            int left = 0, right = mat[i].length - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (mat[i][mid] == 0) right = mid - 1;
                else left = mid + 1;
            }
            cnt_solder[i][0] = left;
            cnt_solder[i][1] = i;
        }
        Arrays.sort(cnt_solder, (a, b)->{
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });
        int[] ans = new int[k];
        for (int i = 0; i < k; i++) {
            ans[i] = cnt_solder[i][1];
        }
        return ans;
    }
}

/**
 * 对于数组自定义排序
 * 使用Arrays.sort(待排序数组, (元素a, b)->{
 *      处理具体的排序逻辑比如逆序，或者高维数组的自定义排序
 * })
 **/