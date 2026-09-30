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
    TreeNode* getParent(TreeNode* root, int key) {
        if (root->val == key)
            return nullptr;
            
        if (key < root->val){
            if (!root->left || root->left->val == key)
                return root;
            return getParent(root->left, key);
        }
        else {
            if (!root->right || root->right->val == key)
                return root;
            return getParent(root->right, key);
        }
    }
    TreeNode* getLeftMostParent(TreeNode* root) {
        if (!root || !root->left)
            return root;
        TreeNode* temp = root;
        while (temp->left->left)
            temp = temp->left;
        return temp;
    }
    TreeNode* getRightMost(TreeNode* root) {
        TreeNode* temp = root;
        while (temp->right)
            temp = temp->right;
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;

        TreeNode* parent = getParent(root, key);
        if (!parent) {
            // Delete the root node, set new root to left-most node in right subtree
            TreeNode* leftmostParent = getLeftMostParent(root->right);
            if (!leftmostParent)
                // No right branch
                root = root->left;
            else if (!leftmostParent->left) {
                // No left subtree in right branch
                leftmostParent->left = root->left;
                root = leftmostParent;
            }
            else {
                TreeNode* leftmost = leftmostParent->left;
                leftmost->left = root->left;
                leftmost->right = root->right;
                leftmostParent->left = nullptr;
                root = leftmost;
            }
        }
        else if ((!parent->left && key < parent->val) ||
                 (!parent->right && key > parent->val))
            // Key not found
            return root;
        else {
            // Delete a child node
            TreeNode* toDel;
            if (parent->left && parent->left->val == key)
                toDel = parent->left;
            else
                toDel = parent->right;
            if (!toDel->left && !toDel->right) {
                // Target node has no children
                if (parent->left == toDel)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }
            else {
                // Target node may has at least one subtree
                TreeNode* leftmostParent = getLeftMostParent(toDel->right);
                if (!leftmostParent) {
                    // No right branch
                    if (parent->left == toDel) {
                        parent->left = toDel->left;
                    }
                    else {
                        parent->right = toDel->left;                        
                    }
                }
                else if (!leftmostParent->left) {
                    // No left subtree in right branch
                    if (parent->left == toDel) {
                        parent->left = toDel->right;
                    }
                    else {
                        parent->right = toDel->right;
                    }
                    toDel->right->left = toDel->left;
                }
                else {
                    TreeNode* temp = leftmostParent->left;
                    leftmostParent->left = nullptr;
                    if (parent->left == toDel) {
                        parent->left = temp;
                    }
                    else {
                        parent->right = temp;
                    }
                    temp->left = toDel->left;
                    // Get right-most node in subtree of the node that will replace toDel. Use the node that will replace toDel (temp) if there is no right branch.
                    TreeNode* rightmost = getRightMost(temp);
                    rightmost->right = toDel->right;
                }
            }
        }

        return root;
    }
};