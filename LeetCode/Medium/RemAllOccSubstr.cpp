class Solution {
public:
    string removeOccurrences(string s, string part) {
        string curr = "";
        int n = part.size();

        for (int i = 0; i < s.size(); i++) {
            curr += s[i];
            if (curr.find(part) != string::npos) {
                for (int i = 0; i < n; i++) {
                    curr.pop_back();
                }
            }
        }

        return curr;
    }
};