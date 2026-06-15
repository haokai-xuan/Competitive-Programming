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
    int getLen(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = getLen(head);
        if (n == 1) return nullptr;

        int mid = n / 2;
        ListNode* prev = head;
        for (int i = 0; i < mid - 1; i++) {
            prev = prev->next;
        }
        ListNode* next = prev->next->next;
        prev->next = next;

        return head;
    }
};