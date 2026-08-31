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
    bool isCritical(ListNode* prev, ListNode* curr) {
        if (prev->val < curr->val && curr->val > curr->next->val) return true;
        else if (prev->val > curr->val && curr->val < curr->next->val) return true;

        return false;
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int pos = 2;
        while (curr->next) {
            if (isCritical(prev, curr)) criticalPoints.push_back(pos);
            pos++;
            prev = curr;
            curr = curr->next;
        }

        if (criticalPoints.size() < 2) return {-1, -1};

        int minDiff = INT_MAX;

        for (int i = 1; i < criticalPoints.size(); i++) {
            int diff = criticalPoints[i] - criticalPoints[i - 1];
            minDiff = min(minDiff, diff);
        }

        minDiff = (minDiff == INT_MAX ? -1 : minDiff);
        int maxDiff = criticalPoints.back() - criticalPoints[0];

        return {minDiff, maxDiff == 0 ? -1 : maxDiff};
    }
};