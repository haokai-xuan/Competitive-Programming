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
    int binToDec(string path) {
        int ans = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            if (path[i] == '1') ans += pow(2, path.size() - i - 1);
        }
        return ans;
    }
    int solve(TreeNode* node, string path) {
        if (!node) return 0;
        path += node->val + '0';
        if (!node->left && !node->right)
            return binToDec(path);
        int left = solve(node->left, path);
        int right = solve(node->right, path);
        return left + right;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return solve(root, "");
    }
};