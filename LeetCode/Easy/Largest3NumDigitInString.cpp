class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int msf = -1;
        int left = 0;
        for (int right = 0; right < num.size(); right++) {
            while (num[left] == num[right]) {
                if (right - left == 2) {
                    msf = max(msf, num[left] - '0');
                    ans = to_string(msf) + to_string(msf) + to_string(msf);
                    break;
                }
                right++;
            }
            if (num[left] != num[right]) {
                right--;
                left++;
            }
        }

        return ans;
    }
};