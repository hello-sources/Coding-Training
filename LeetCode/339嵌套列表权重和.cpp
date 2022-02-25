/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Initializes an empty nested list and return a reference to the nested integer.
 * struct NestedInteger *NestedIntegerInit();
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Set this NestedInteger to hold a single integer.
 * void NestedIntegerSetInteger(struct NestedInteger *ni, int value);
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 * void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */
int dfs(struct NestedInteger **nestedList, int nestedListSize, int dep) {
    if (nestedList == NULL) return 0;
    int cnt = 0;
    for (int i = 0; i < nestedListSize; i++) {
        if (NestedIntegerIsInteger(nestedList[i])) cnt += dep * NestedIntegerGetInteger(nestedList[i]);
        else cnt += dfs(NestedIntegerGetList(nestedList[i]), NestedIntegerGetListSize(nestedList[i]), dep + 1);
    }
    return cnt;
}

int depthSum(struct NestedInteger** nestedList, int nestedListSize){
    if (nestedList == NULL || nestedListSize <= 0) return 0;
    int dep = 1;
    return dfs(nestedList, nestedListSize, dep);
}