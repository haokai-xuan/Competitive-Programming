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
    void getInorder(TreeNode* root, vector<int>& inorder) {
        if (!root) return;
        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }
    TreeNode* buildBalanced(vector<int>& inorder, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = buildBalanced(inorder, l, mid - 1);
        root->right = buildBalanced(inorder, mid + 1, r);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        getInorder(root, inorder);
        return buildBalanced(inorder, 0, inorder.size() - 1);
    }
};