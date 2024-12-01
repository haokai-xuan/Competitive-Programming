/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum, 0);
    }

    bool solve(TreeNode* root, int ts, int curr) {
        if (!root) {
            return false;
        }
        curr += root->val;
        if (!root->left && !root->right) {
            return ts == curr;
        }

        return (solve(root->left, ts, curr) || solve(root->right, ts, curr));
    }
};
