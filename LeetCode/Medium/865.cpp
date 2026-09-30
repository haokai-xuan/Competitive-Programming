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
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};
        pair<int, TreeNode*> left = dfs(node->left);
        pair<int, TreeNode*> right = dfs(node->right);
        TreeNode* lca;
        if (left.first == right.first) lca = node;
        else lca = left.first > right.first ? left.second : right.second;
        return {max(left.first, right.first) + 1, lca};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<int, TreeNode*> ans = dfs(root);
        return ans.second;
    }
};