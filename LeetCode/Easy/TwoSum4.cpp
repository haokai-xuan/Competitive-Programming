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
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        get_list(root, v);

        int left = 0;
        int right = v.size() - 1;

        while (left < right) {
            if (v[left] + v[right] < k)
                left++;
            else if (v[left] + v[right] > k)
                right--;
            else 
                return true;
        }

        return false;
    }

private:
    void get_list(TreeNode *root, vector<int> &v) {
        if (!root)
            return;    
        get_list(root->left, v);
        v.push_back(root->val);
        get_list(root->right, v);
    }
};