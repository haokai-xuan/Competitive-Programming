class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int run = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') run++;
            else run--;
            if (run == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                string bestInner = makeLargestSpecial(inner);
                parts.push_back("1" + bestInner + "0");
                start = i + 1;
            }
        }
        sort(parts.begin(), parts.end(), greater<string>());
        string res = "";
        for (auto& p : parts) res += p;
        return res;
    }
};