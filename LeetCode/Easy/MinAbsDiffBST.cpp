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
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        int mindiff = 1e5 + 1;

        helper(root, prev, mindiff);
        return mindiff;
    }
    void helper(TreeNode* node, int& prev, int& mindiff) {
        if (node == NULL) {
            return;
        }

        helper(node->left, prev, mindiff);

        if (prev != -1) {
            mindiff = min(mindiff, abs(node->val - prev));
        }
        prev = node->val;

        helper(node->right, prev, mindiff);
    }
};
