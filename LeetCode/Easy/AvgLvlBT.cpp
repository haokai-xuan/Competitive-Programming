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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;

        q.push(root);
        
        double avg;
        while (!q.empty()) {
            int level_size = q.size();
            double level_sum = 0;

            for (int i = 0; i < level_size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                level_sum += curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(level_sum / level_size);
        }

        return ans;
    }
};