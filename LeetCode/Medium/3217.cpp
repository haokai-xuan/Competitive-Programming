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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for (auto& i : nums) s.insert(i);
        ListNode* curr = head;
        ListNode* ans = nullptr;
        ListNode* prev = nullptr;
        while (curr) {
            if (s.count(curr->val)) {
                curr = curr->next;
                if (prev)
                    prev->next = curr;
            }
            else {
                if (!ans) ans = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        return ans;
    }
};