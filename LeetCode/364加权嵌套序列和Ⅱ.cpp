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
int max_depth(struct NestedInteger **nestedList, int nestedListSize) {
    int depth = 0;
    for (int i = 0; i < nestedListSize; i++) {
        struct NestedInteger *n = *(nestedList + i);
        if (NestedIntegerIsInteger(n)) continue;
        depth = fmax(depth, max_depth(NestedIntegerGetList(n), NestedIntegerGetListSize(n)));
    }
    return depth + 1;
}

int dfs(struct NestedInteger ** nestedList, int nestedListSize, int depth, int max_depth) {
    int ans = 0;
    for (int i = 0; i < nestedListSize; i++) {
        struct NestedInteger *n = *(nestedList + i);
        ans += NestedIntegerIsInteger(n) 
                ? NestedIntegerGetInteger(n) * (max_depth - depth + 1) 
                : dfs(NestedIntegerGetList(n), NestedIntegerGetListSize(n), depth + 1, max_depth);

    }
    return ans;
}

int depthSumInverse(struct NestedInteger** nestedList, int nestedListSize){
    return dfs(nestedList, nestedListSize, 1, max_depth(nestedList, nestedListSize));
}