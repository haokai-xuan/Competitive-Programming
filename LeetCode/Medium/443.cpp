class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        char prev = chars[0];
        int cnt = 0;
        for (int i = 0; i < chars.size(); i++) {
            if (chars[i] == prev) cnt++;
            else if (cnt == 0) {
                cnt++;
                prev = chars[i];
            }
            else {
                if (cnt == 1)
                    chars[index++] = prev;
                else {
                    chars[index++] = prev;
                    string len = to_string(cnt);
                    for (char& c : len) chars[index++] = c;
                }
                cnt = 1;
                prev = chars[i];
            }
        }

        if (cnt == 1) chars[index++] = prev;
        else if (cnt >= 2) {
            chars[index++] = prev;
            string len = to_string(cnt);
            for (char& c : len) chars[index++] = c;
        }

        return index;
    }
};