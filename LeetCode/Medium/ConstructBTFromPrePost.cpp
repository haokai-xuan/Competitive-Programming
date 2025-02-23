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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int num_nodes = preorder.size();

        vector<int> postorder_index(num_nodes + 1);

        for (int i = 0; i < num_nodes; i++) {
            postorder_index[postorder[i]] = i;
        }

        return construct_tree(0, num_nodes - 1, 0, preorder, postorder_index);
    }

private:
    TreeNode *construct_tree(int i1, int i2, int j1, vector<int> &preorder, vector<int> &postorder_index) {
        if (i1 > i2) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[i1]);

        if (i1 != i2) {
            int left_val = preorder[i1 + 1];
            int mid = postorder_index[left_val];
            int left_size = mid - j1 + 1;
            root->left = construct_tree(i1 + 1, i1 + left_size, j1, preorder, postorder_index);
            root->right = construct_tree(i1 + left_size + 1, i2, mid + 1, preorder, postorder_index);
        }

        return root;
    }
};