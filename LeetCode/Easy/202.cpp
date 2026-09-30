class Solution {
public:
    bool isHappy(int n) {
        string s = to_string(n);

        unordered_map<int, int> mp;
        while (mp.find(n) == mp.end()) {
            mp[n];

            n = 0;
            for (char ch : s) {
                n += (ch - '0') * (ch - '0');
            }
            if (n == 1) {
                return true;
            }
            s = to_string(n);
        }
        return false;
    }
};
