class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int options = pow(2, k);
        unordered_set<string> codes;

        for (int i = 0; i <= static_cast<int>(s.size()) - k; i++) {
            string code = s.substr(i, k);
            codes.insert(code);
        }

        return codes.size() == options;
    }
};