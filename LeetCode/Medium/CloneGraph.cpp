/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        Node *new_node = new Node();
        new_node->val = node->val;

        solve(new_node, node);

        return new_node;
    }

private:
    unordered_map<int, Node*> vis;
    void solve(Node *curr, Node *orig) {
        vis[curr->val] = curr;
        for (Node *n : orig->neighbors) {
            if (vis.find(n->val) != vis.end() &&
                find(curr->neighbors.begin(), curr->neighbors.end(), vis[n->val]) == curr->neighbors.end()) {
                curr->neighbors.push_back(vis[n->val]);
                vis[n->val]->neighbors.push_back(curr);
                continue;
            }
            Node *new_node = new Node();
            new_node->val = n->val;
            if (vis.find(n->val) == vis.end()) {
                solve(new_node, n);
            }
        }
    }
};