class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int len = code.size();
        vector<int> ans;
        for (int i = 0; i < len; i++) {
            int j = 0;
            int sum = 0;
            while (j < k) {
                sum += code[(++j + i) % len];
            }
            while (j > k) {
                sum += code[(((i + --j) % len) + len) % len];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};