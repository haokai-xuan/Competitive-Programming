/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int dfs(TreeNode* node, bool& balanced) {
        if (!node) return 0;
        int leftDepth = dfs(node->left, balanced);
        int rightDepth = dfs(node->right, balanced);
        if (abs(leftDepth - rightDepth) > 1) balanced = false;
        return 1 + max(leftDepth, rightDepth);
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        bool balanced = true;
        dfs(root, balanced);
        return balanced;
    }
};