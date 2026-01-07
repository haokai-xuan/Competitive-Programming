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
    long long treeSum;
    long long best = 0;
    const int MOD = 1e9 + 7;
    int getTreeSum(TreeNode* node) {
        if (!node) return 0;
        return node->val + getTreeSum(node->left) + getTreeSum(node->right);
    }
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int leftSum = dfs(node->left);
        int rightSum = dfs(node->right);
        if (node->left) {
            best = max(best, leftSum * (treeSum - leftSum));
        }
        if (node->right) {
            best = max(best, rightSum * (treeSum - rightSum));
        }
        return node->val + leftSum + rightSum;
    }
public:
    int maxProduct(TreeNode* root) {
        treeSum = getTreeSum(root);
        dfs(root);
        return best % MOD;
    }
};