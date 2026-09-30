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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        vector<vector<pair<int, int>>> newDesc(1e5 + 1);
        unordered_set<int> nonRoots;
        for (auto& d : descriptions) {
            nonRoots.insert(d[1]);
            newDesc[d[0]].push_back({d[1], d[2]});
        }

        int rootVal;
        for (auto& d : descriptions) {
            if (!nonRoots.count(d[0])) {
                rootVal = d[0];
                break;
            }
        }

        TreeNode* root = new TreeNode{rootVal};
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                for (int j = 0; j < newDesc[node->val].size(); j++) {
                    TreeNode* childNode = new TreeNode{newDesc[node->val][j].first};
                    if (newDesc[node->val][j].second) {
                        node->left = childNode;
                    }
                    else {
                        node->right = childNode;
                    }
                    q.push(childNode);
                }
            }
        }

        return root;
    }
};