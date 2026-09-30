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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postorder_index = n - 1;
        TreeNode* root = helper(inorder, postorder, postorder_index, 0, n - 1);

        return root;
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,
                     int& postorder_index, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        TreeNode* node = new TreeNode();
        node->val = postorder[postorder_index];

        postorder_index--;

        int inorderIndex = getInorderIndex(
            inorder, postorder[postorder_index + 1], start, end);

        node->right =
            helper(inorder, postorder, postorder_index, inorderIndex + 1, end);
        node->left = helper(inorder, postorder, postorder_index, start, inorderIndex - 1);

        return node;
    }

    int getInorderIndex(vector<int>& inorder, int val, int start, int end) {
        int i;
        for (i = start; i <= end; i++) {
            if (inorder[i] == val) {
                break;
            }
        }

        return i;
    }
};