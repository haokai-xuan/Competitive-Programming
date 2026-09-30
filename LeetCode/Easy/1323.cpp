class Solution {
public:
    int maximum69Number (int num) {
        int ans = 0;
        string sNum = to_string(num);
        bool changed = false;
        for (int i = 0; i < sNum.size(); i++) {
            ans *= 10;
            if (!changed && sNum[i] == '6') {
                ans += 9;
                changed = true;
            }
            else if (sNum[i] == '6') {
                ans += 6;
            }
            else {
                ans += 9;
            }
        }

        return ans;
    }
};