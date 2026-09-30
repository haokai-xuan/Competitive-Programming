class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_map<int, int> mp; // elem val -> index
        vector<int> assigned;

        for (int i = 0; i < elements.size(); i++) {
            if (mp.count(elements[i]) == 0) {
                mp[elements[i]] = i;
            }
        }

        for (int i = 0; i < groups.size(); i++) {
            check(groups[i], mp, assigned);
        }

        return assigned;
    }

private:
    void check(int group_val, unordered_map<int, int> &mp, vector<int> &assigned) {
        int k = INT_MAX;

        for (int i = 1; i * i <= group_val; i++) {
            if (group_val % i == 0 && mp.count(i)) {
                k = min(k, mp[i]);
            }

            if (group_val % i == 0 && mp.count(group_val / i)) {
                k = min(k, mp[group_val / i]);
            }
        }

        if (k == INT_MAX)
            assigned.push_back(-1);
        else
            assigned.push_back(k);
    }
};