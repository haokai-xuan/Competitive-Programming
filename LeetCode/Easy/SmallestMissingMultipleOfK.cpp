class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> s;
        int mult = k;
        for (auto& n : nums) s.insert(n);
        while (true) {
            if (!s.count(mult)) return mult;
            mult += k;
        }
    }
};