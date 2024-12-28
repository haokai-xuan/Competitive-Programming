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
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        return is_sorted(v.begin(), v.end()) && adjacent_find(v.begin(), v.end()) == v.end();
    }
    void helper(TreeNode* root, vector<int>& v) {
        if (root == NULL) {
            return;
        }
        
        helper(root->left, v);

        v.push_back(root->val);

        helper(root->right, v);
    }
};