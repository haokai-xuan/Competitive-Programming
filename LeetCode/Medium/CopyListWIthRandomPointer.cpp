/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* newHead = head ? new Node{head->val} : nullptr;
        Node* curr = newHead;
        Node* orig = head;
        while (orig) {
            mp[orig] = curr;
            if (mp.find(orig->next) != mp.end()) {
                curr->next = mp[orig->next];
            }
            else if (orig->next) {
                curr->next = new Node{orig->next->val};
            }

            mp[orig->next] = curr->next;

            if (mp.find(orig->random) != mp.end()) {
                curr->random = mp[orig->random];
            }
            else if (orig->random) {
                curr->random = new Node{orig->random->val};
            }

            mp[orig->random] = curr->random;

            curr = curr->next;
            orig = orig->next;
        }

        return newHead;
    }
};