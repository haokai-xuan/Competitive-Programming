class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        int ans = 0;

        while (pq.top() < k) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();

            pq.push(min(first, second) * 2 + max(first, second));
            ans++;
        }

        return ans;
    }
};