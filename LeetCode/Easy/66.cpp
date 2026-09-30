class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;

        int temp;
        for (int i = digits.size() - 1; i >= 0; i--) {
            temp = digits[i] + 1;
            digits[i] = temp % 10;

            if (temp < 10) {
                break;
            }
            if (i == 0) {
                v.push_back(1);
            }
        }
        if (!v.empty()) {
            for (int i : digits) {
                v.push_back(i);
            }
            return v;
        }

        return digits;
    }
};
