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
class Solution
{
public:
  TreeNode *invertTree(TreeNode *root)
  {
    if (root == nullptr)
    {
      return nullptr;
    }

    TreeNode *temp = new TreeNode();
    temp->val = root->val;
    temp->left = invertTree(root->right);
    temp->right = invertTree(root->left);

    return temp;
  }
};