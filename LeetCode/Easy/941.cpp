class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        bool reachedMax = false;
        int maxIdx = -1;
        int prev = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (!reachedMax) {
                if (arr[i] < prev) {
                    reachedMax = true;
                    maxIdx = i - 1;
                    prev = arr[i];
                }
                else if (arr[i] == prev) return false;
                else prev = arr[i];
            }
            else {
                if (arr[i] >= prev) return false;
                prev = arr[i];
            }
        }
        return reachedMax && maxIdx != 0 && maxIdx < arr.size() - 1;
    }
};