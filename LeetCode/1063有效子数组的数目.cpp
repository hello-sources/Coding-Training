int dfs(int *nums, int head, int tail, int num) {
    if (head == tail) {
        if (nums[head] < num) return 0;
        return 1;
    }
    if (nums[head] < num) return 0;
    return 1 + dfs(nums, head + 1, tail, num);
}

int validSubarrays(int* nums, int numsSize){
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        cnt += dfs(nums, i, numsSize - 1, nums[i]);
    }
    return cnt;
}
/************
第一个解法想到就是递归求解，可以把子数组想象成一个数，从根节点到每一个叶子节点都是一个子数组，例如：
1->4->2->5->3
按照叶子节点访问，依次组成的数组是：
(1)、(1,4)、(1,4,2)、(1,4,2,5)、(1,4,2,5,3)
那么每次递归判断如果首字母是最小的，那该叶子节点就返回满足条件的子数组+1的结果，按照这个思路写出最后的代码
************/