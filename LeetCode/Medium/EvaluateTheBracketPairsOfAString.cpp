class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> values;
        for (const auto& pair : knowledge) {
            values[pair[0]] = pair[1];
        }

        string result;
        for (int i = 0; i < s.size(); ) {
            if (s[i] != '(') {
                result += s[i++];
                continue;
            }

            int end = s.find(')', i);
            string key = s.substr(i + 1, end - i - 1);
            auto it = values.find(key);
            result += (it == values.end() ? "?" : it->second);
            i = end + 1;
        }

        return result;
    }
};