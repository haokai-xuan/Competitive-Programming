class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int now = 0;
        int prev = 0;
        int ans = 0;
        for (int i = 0; i < bank.size(); i++) {
            for (int j = 0; j < bank[i].size(); j++) {
                if (bank[i][j] == '1')
                    now++;
            }
            ans += prev * now;
            if (now > 0)
                prev = now;
            now = 0;
            now = 0;
        }
        return ans;
    }
};