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
    int ans = 0;

    pair<int, int> solve(TreeNode* root) {
        if (!root) return {0, 0};
        if (!root->left && !root->right) {
            ans++;
            return {root->val, 1};
        }

        pair<int, int> lRes = solve(root->left);
        pair<int, int> rRes = solve(root->right);

        int sum = lRes.first + rRes.first + root->val;
        int numNodes = lRes.second + rRes.second + 1;
        int avg = sum / numNodes;

        if (avg == root->val) ans++;

        return {sum, numNodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        solve(root);

        return ans;
    }
};