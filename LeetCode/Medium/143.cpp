/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* curr = head;
        while (curr) {
            v.push_back(curr);
            curr = curr->next;
        }
        int l = 0, r = v.size() - 1;
        ListNode* prev = nullptr;
        while (l < r) {
            if (prev) prev->next = v[l];
            v[l]->next = v[r];
            prev = v[r];
            l++;
            r--;
        }
        if (l == r && l != 0) {
            prev->next = v[r];
            v[r]->next = nullptr;
        }
        else if (prev) prev->next = nullptr;
    }
};