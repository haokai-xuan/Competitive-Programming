class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> on(101, false);
        for (auto& b : bulbs) {
            on[b] = !on[b];
        }
        vector<int> ans;
        for (int i = 1; i <= 100; i++) {
            if (on[i]) ans.push_back(i);
        }
        return ans;
    }
};