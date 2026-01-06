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
    int maxLevelSum(TreeNode* root) {
        int levelMax = INT_MIN;
        int curr = 1;
        int ans;
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> level;
        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                levelSum += node->val;
            }
            if (levelSum > levelMax) {
                levelMax = levelSum;
                ans = curr;
            }
            curr++;
        }
        return ans;
    }
};