/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node *backtracking(int r0, int c0, int r1, int c1,vector<vector<int>>& grid) {
        for (int i = r0; i < r1; i++) {
            for (int j = c0; j < c1; j++) {
                if (grid[i][j] != grid[r0][c0]) {
                    return new Node(true, false, 
                        backtracking(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2, grid),
                        backtracking(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1, grid),
                        backtracking((r0 + r1) / 2, c0, r1, (c0 + c1) / 2, grid),
                        backtracking((r0 + r1) / 2, (c0 + c1) / 2, r1, c1, grid));
                }
            }
        }
        return new Node(grid[r0][c0], true);
    }

    Node* construct(vector<vector<int>>& grid) {
        return backtracking(0, 0, grid.size(), grid.size(), grid);
    }
};