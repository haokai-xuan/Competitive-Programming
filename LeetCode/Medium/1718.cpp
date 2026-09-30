class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int len = 2 * n - 1;
        vector<int> v(len, 0);
        vector<bool> used(n + 1, false);

        solve(v, used, n);
        return v;
    }

private:
    bool solve(vector<int> &v, vector<bool> &used, int n) {
        if (filled(used))
            return true;

        for (int i = n; i >= 1; i--) {
            if (!used[i]) {
                int len = v.size();
                int pos = 0;
                while (pos < len && v[pos]) {
                    pos++;
                }

                if (i >= 2) {
                    if (pos + i < len && v[pos + i] == 0) {
                        v[pos] = i;
                        v[pos + i] = i;
                    }
                    else {
                        continue;
                    }
                }
                else if (i == 1) {
                    v[pos] = i;
                }
                used[i] = true;

                if (solve(v, used, n)) {
                    return true;
                }
                else {
                    v[pos] = 0;
                    if (i != 1)
                        v[pos + i] = 0;
                    used[i] = false;
                }
            }
        }
        

        return false;
    }

    bool filled(vector<bool> &used) {
        int len = used.size();
        for (int i = 1; i < len; i++) {
            if (!used[i])
                return false;
        }

        return true;
    }
};