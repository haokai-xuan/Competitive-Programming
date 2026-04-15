class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            int idx = (startIndex + i) % n;
            if (words[idx] == target) ans = min(ans, min(i, n - i));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};