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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode();
        ListNode* tail = &dummy;

        int carry = 0;

        while (l1 && l2) {
            int sum = 0;
            sum += l1->val + l2->val + carry;

            carry = sum / 10;
            sum = sum % 10;
            
            tail->next = new ListNode(sum);

            l1 = l1->next;
            l2 = l2->next;

            tail = tail->next;
        }

        if (carry) {
            while (carry) {
                int sum = 0;

                if (l1) {
                    sum += l1->val;
                }
                if (l2) {
                    sum += l2->val;
                }

                sum += carry;

                carry = sum / 10;
                sum = sum % 10;

                ListNode* temp = new ListNode(sum);

                tail->next = temp;
                tail = tail->next;

                if (l1) {
                    l1 = l1->next;
                }
                if (l2) {
                    l2 = l2->next;
                }
            } 
        }

        tail->next = (l1) ? l1 : l2;


        return dummy.next;
    }
};