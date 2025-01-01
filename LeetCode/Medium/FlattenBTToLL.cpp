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
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }

        root = helper(root);
    }

    TreeNode* helper(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        TreeNode* nodeRight = root->right;

        root->right = helper(root->left);
        root->left = nullptr;
        
        TreeNode* temp = root;
        if (nodeRight) {
            while (temp->right) {
                temp = temp->right;
            }

            temp->right = helper(nodeRight);
        }

        return root;
    }
};