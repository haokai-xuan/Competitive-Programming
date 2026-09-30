class Solution {
public:
    string toLower(string& s) {
        string res = s;
        for (auto& c : res) {
            if (c >= 'A' && c <= 'Z') {
                c = c + 'a' - 'A';
            }
        }
        return res;
    }

    bool isVowel(char c) {
        string vowels = "aeiou";

        for (char& v : vowels) {
            if (c == v || c == v - ('a' - 'A'))
            return true;
        }

        return false;
    }

    string normalize(string& s) {
        string res = s;
        for (auto& c : res) {
            if (isVowel(c))
                c = '*';
        }
        return res;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> lowered;
        unordered_map<string, string> norm;
        for (auto& s : wordlist) {
            exact.insert(s);
            string l = toLower(s);
            if (!lowered.count(l))
                lowered[l] = s;
            string v = normalize(l);
            if (!norm.count(v))
                norm[v] = s;
        }
        
        vector<string> ans;
        for (auto& q : queries) {
            string l = toLower(q);
            string n = normalize(l);
            if (exact.count(q))
                ans.push_back(q);
            else if (lowered.count(l))
                ans.push_back(lowered[l]);
            else if (norm.count(n))
                ans.push_back(norm[n]);
            else
                ans.push_back("");
        }

        return ans;
    }
};