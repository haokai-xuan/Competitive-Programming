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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int n = 1;
        ListNode* curr = head;
        while (curr->next) {
            n++;
            curr = curr->next;
        }
        curr->next = head;

        int tailIdx = n - k % n - 1;
        if (tailIdx == n - 1) {
            curr->next = nullptr;
            return head;
        }
        curr = head;
        for (int i = 0; i < tailIdx; i++) {
            curr = curr->next;
        }
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
};