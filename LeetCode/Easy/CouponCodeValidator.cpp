class Solution {
    bool validCode(string code) {
        if (code.empty()) return false;
        for (char& c : code) {
            if (!('a' <= c && c <= 'z') && !('A' <= c && c <= 'Z') && !('0' <= c && c <= '9') && c != '_') return false;
        }
        return true;
    }
    bool validLine(string line) {
        return line == "electronics" || line == "grocery" || line == "pharmacy" || line == "restaurant";
    }
    bool isActive(bool active) {
        return active;
    }
public:
    bool valid(string code, string line, bool active) {
        return validCode(code) && validLine(line) && isActive(active);
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, vector<string>> mp;
        vector<string> ans;
        for (int i = 0; i < code.size(); i++) {
            if (valid(code[i], businessLine[i], isActive[i])) mp[businessLine[i]].push_back(code[i]);
        }
        for (auto& [s, v] : mp) {
            sort(v.begin(), v.end());
        }
        for (auto& s : {"electronics", "grocery", "pharmacy", "restaurant"}) {
            ans.insert(ans.end(), mp[s].begin(), mp[s].end());
        }
        return ans;
    }
};