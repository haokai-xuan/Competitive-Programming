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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preorder_index = 0;
        TreeNode* root = helper(preorder, inorder, preorder_index, 0, n - 1);

        return root;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int& preorder_index, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        TreeNode* node = new TreeNode();
        node->val = preorder[preorder_index];
        preorder_index++;

        int inorder_index =
            getInorderIndex(inorder, preorder[preorder_index - 1], start, end);

            node->left = helper(preorder, inorder, preorder_index, start, inorder_index - 1);
            node->right = helper(preorder, inorder, preorder_index, inorder_index + 1, end);
        
        return node;
    }

    int getInorderIndex(vector<int>& inorder, int val, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }

        return -1;
    }
};