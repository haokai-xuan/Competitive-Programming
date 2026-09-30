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
    int solve(TreeNode* node, bool leftSubtree) {
        if (!node) return 0;
        if (leftSubtree && !node->left && !node->right) return node->val;
        
        return solve(node->left, true) + solve(node->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, false);
    }
};