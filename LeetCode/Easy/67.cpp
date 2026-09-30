class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0)
                sum += a[i] - '0';
            if (j >= 0)
                sum += b[j] - '0';

            i--;
            j--;

            s += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(s.begin(), s.end());

        return s;
    }
};