class Solution {
    void generate(string s, int n, int idx, vector<string>& happy) {
        if (s.size() == n) {
            happy.push_back(s);
            return;
        }
        for (char c : {'a', 'b', 'c'}) {
            if (idx == 0 || s[idx - 1] != c) {
                generate(s + c, n, idx + 1, happy);
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> happy;

        generate("", n, 0, happy);

        if (happy.size() < k) return "";
        sort(happy.begin(), happy.end());
        return happy[k - 1];
    }
};