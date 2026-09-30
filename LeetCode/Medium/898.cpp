class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> curr;
        unordered_set<int> ans;
        for (int& i : arr) {
            unordered_set<int> newCurr;
            newCurr.insert(i);
            for (const int& j : curr)
                newCurr.insert(i | j);
            
            curr = newCurr;
            ans.insert(curr.begin(), curr.end());
        }
        return ans.size();
    }
};