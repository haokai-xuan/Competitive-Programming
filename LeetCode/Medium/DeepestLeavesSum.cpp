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
    void solve(TreeNode* node, int depth, vector<int>& rowSum) {
        if (!node) return;
        if (depth == rowSum.size()) rowSum.push_back(node->val);
        else rowSum[depth] += node->val;
        solve(node->left, depth + 1, rowSum);
        solve(node->right, depth + 1, rowSum);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<int> rowSum;
        solve(root, 0, rowSum);
        return rowSum.back();
    }
};