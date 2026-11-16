class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string curr = "";
            for (int i = 0; i < s.size(); i += k) {
                string substr = s.substr(i, k);
                
                int newNum = 0;
                for (char c : substr) {
                    int digit = c - '0';
                    newNum += digit;
                }
                curr += to_string(newNum);
            }
            s = curr;
        }
        return s;
    }
};