class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26, 0);
        vector<bool> visited(26, false);
        for (char& c : s) cnt[c - 'a']++;
        string st = "";
        
        for (char& c : s) {
            cnt[c - 'a']--;
            if (visited[c - 'a']) continue;
            while (!st.empty() && st.back() > c && cnt[st.back() - 'a'] > 0) {
                visited[st.back() - 'a'] = false;
                st.pop_back();
            }
            st += c;
            visited[c - 'a'] = true;
        }

        return st;
    }
};