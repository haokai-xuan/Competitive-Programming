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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int len = traversal.size();
        int depth = 0;

        TreeNode* root = nullptr;

        int i = 0;
        while (i < len) {
            while (i < len && traversal[i] == '-') {
                depth++;
                i++;
            }

            int num = 0;
            while (i < len && isdigit(traversal[i])) {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(num);

            if (!root) {
                root = node;
                st.push(root);
                continue;
            }

            while (st.size() > depth) {
                st.pop();
            }

            TreeNode *temp = st.top();
            if (!temp->left)
                temp->left = node;
            else
                temp->right = node;
            st.push(node);

            depth = 0;
        }

        return root;
    }
};