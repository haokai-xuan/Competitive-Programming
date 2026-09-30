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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return inOrderTrav(root, k, cnt);
    }

    int inOrderTrav(TreeNode* root, int k, int& cnt) {
        if (root == NULL) {
            return -1;
        }

        int leftres = inOrderTrav(root->left, k, cnt);

        if (leftres != -1) {
            return leftres;
        }

        cnt++;
        if (cnt == k) {
            return root->val;
        }

        int rightres = inOrderTrav(root->right, k, cnt);
        return rightres;
    }
};