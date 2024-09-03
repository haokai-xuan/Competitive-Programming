class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};

        int sum = 0;
        int temp = 0;

        for (int i = 0; i < s.size(); ++i) {
            temp += mp[s[i]];
            if (s[i] == 'I' && s[i + 1] == 'V' ||
                s[i] == 'X' && s[i + 1] == 'L' ||
                s[i] == 'C' && s[i + 1] == 'D') {
                temp *= 4;
                ++i;
            } else if (s[i] == 'I' && s[i + 1] == 'X' ||
                       s[i] == 'X' && s[i + 1] == 'C' ||
                       s[i] == 'C' && s[i + 1] == 'M') {
                temp *= 9;
                ++i;
            }
            sum += temp;
            temp = 0;
        }
        return sum;
    }
};
