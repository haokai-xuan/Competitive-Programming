class Solution {
public:
    string smallestNumber(string pattern) {
        unordered_map<char, bool> mp = {
            {'1', false}, {'2', false}, {'3', false},
            {'4', false}, {'5', false}, {'6', false},
            {'7', false}, {'8', false}, {'9', false},
        };
        for (int i = 1; i <= 9; i++) {
            string curr;
            curr.push_back(i + '0');
            mp[i] = true;
            if (solve(mp, pattern, curr)) {
                return curr;
            }
            mp[i] = false;
        }
        return "";
    }

private:
    bool solve(unordered_map<char, bool>& mp, string pattern, string& curr) {
        if (pattern.size() + 1 == curr.size())
            return true;

        int prev_pos = curr.size() - 1;
        int prev_num = curr.back() - '0';
        int lowest;
        for (int i = 1; i <= 9; i++) {
            if (!mp[i]) {
                lowest = i;
                break;
            }
        }

        if (pattern[prev_pos] == 'D' && lowest > prev_num)
            return false;

        for (int i = lowest; i <= 9; i++) {
            if (!mp[i]) {
                curr.push_back(i + '0');
                mp[i] = true;
                if (solve(mp, pattern, curr))
                    return true;
                curr.pop_back();
                mp[i] = false;
                if (pattern[prev_pos] == 'D' && i + 1 >= prev_num)
                    return false;
            }
        }
        return false;
    }
};