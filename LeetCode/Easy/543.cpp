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
    int solve(TreeNode* node, int& ans) {
        if (!node)
            return -1;
        int lenLeft = solve(node->left, ans) + 1;
        int lenRight = solve(node->right, ans) + 1;
        ans = max(ans, lenLeft + lenRight);
        return max(lenLeft, lenRight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};