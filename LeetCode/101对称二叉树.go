/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func isSymmetric(root *TreeNode) bool {
    var que []*TreeNode
    if root == nil {
        return true
    }
    que = append(que, root.Left)
    que = append(que, root.Right)
    for len(que) > 0 {
        leftNode := que[0]
        rightNode := que[1]
        que = que[2:]
        if leftNode == nil && rightNode == nil {
            continue
        }
        if leftNode == nil || rightNode == nil || leftNode.Val != rightNode.Val {
            return false
        }
        que = append(que, leftNode.Left, rightNode.Right, leftNode.Right, rightNode.Left)
    }
    return true
}