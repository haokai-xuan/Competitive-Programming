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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> v;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> lvl;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = q.front();
                q.pop();

                lvl.push_back(currNode->val);

                if (currNode->left) {
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    q.push(currNode->right);
                }
            }
            
            if (leftToRight) {
                v.push_back(lvl);
            }
            else {
                reverse(lvl.begin(), lvl.end());
                v.push_back(lvl);
            }
            leftToRight = !leftToRight;
        }

        return v;
    }
};