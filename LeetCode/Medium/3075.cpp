class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int selected = 0;
        long long ans = 0;
        sort(happiness.begin(), happiness.end());
        for (int i = happiness.size() - 1; i >= 0 && selected < k; i--) {
            ans += max(0, happiness[i] - selected);
            selected++;
        }
        return ans;
    }
};