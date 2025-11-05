class Helper {
    int x;
    long long result;
    set<pair<int, int>> topX, rest;
    unordered_map<int, int> occ;
    void internalInsert(const pair<int, int>& p) {
        if (topX.size() < x || p > *topX.begin()) {
            result += static_cast<long long>(p.first) * p.second;
            topX.insert(p);
            if (topX.size() > x) {
                result -= static_cast<long long>(topX.begin()->first) * topX.begin()->second;
                auto temp = *topX.begin();
                topX.erase(temp);
                rest.insert(temp);
            }
        }
        else {
            rest.insert(p);
        }
    }
    void internalRemove(const pair<int, int>& p) {
        if (p < *topX.begin()) {
            rest.erase(p);
        }
        else {
            result -= static_cast<long long>(p.first) * p.second;
            topX.erase(p);
            if (!rest.empty()) {
                auto newP = *rest.rbegin();
                topX.insert(newP);
                result += static_cast<long long>(newP.first) * newP.second;
                rest.erase(newP);
            }
        }
    }
public:
    Helper(int x) : x{x}, result{0} {}
    void insert(int num) {
        if (occ[num])
            internalRemove({occ[num], num});
        occ[num]++;
        internalInsert({occ[num], num});
    }
    void remove(int num) {
        internalRemove({occ[num], num});
        occ[num]--;
        if (occ[num])
            internalInsert({occ[num], num});
    }
    long long get() {
        return result;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        Helper h(x);
        vector<long long> ans;
        for (int i = 0; i < nums.size(); i++) {
            h.insert(nums[i]);
            if (i >= k)
                h.remove(nums[i - k]);
            if (i >= k - 1)
                ans.push_back(h.get());
        }
        return ans;
    }
};