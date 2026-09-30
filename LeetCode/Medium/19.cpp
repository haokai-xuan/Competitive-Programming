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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        v.push_back(0); // dummy
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            v.push_back(curr);
            curr = curr->next;
            len++;
        }
        int toRmv = len - n + 1;
        if (toRmv == 1)
            head = head->next;
        else
            v[toRmv - 1]->next = v[toRmv]->next;

        return head;
    }
};