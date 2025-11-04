class Solution {
    int getXSum(vector<int>& v, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (int i = 1; i <= 50; i++) {
            pq.push({v[i], i});
        }
        int ans = 0;
        for (int i = 0; i < x; i++) {
            if (pq.empty()) break;
            ans += pq.top().first * pq.top().second;
            pq.pop();
        }
        return ans;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> v(51, 0);
        vector<int> ans;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]]++;
            if (i - left + 1 == k) {
                ans.push_back(getXSum(v, x));
                v[nums[left]]--;
                left++;
            }
        }
        return ans;
    }
};