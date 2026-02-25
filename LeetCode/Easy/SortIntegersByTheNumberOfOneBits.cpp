class Solution {
    unordered_map<int, int> mp;
    int setBits(int i) {
        int ans = 0;
        while (i) {
            if (i & 1) ans++;
            i >>= 1;
        }
        return ans;
    }
    void merge(vector<int>& arr, vector<int>& left, vector<int>& right) {
        int lIdx = 0, rIdx = 0;
        int lSize = left.size(), rSize = right.size();
        int idx = 0;
        while (lIdx < lSize || rIdx < rSize) {
            int lBits = lIdx < lSize ? mp[left[lIdx]] : -1, rBits = rIdx < rSize ? mp[right[rIdx]] : -1;
            if (rIdx >= rSize || (lIdx < lSize && lBits <= rBits)) {
                if (lBits == rBits) {
                    if (left[lIdx] < right[rIdx])
                        arr[idx++] = left[lIdx++];
                    else
                        arr[idx++] = right[rIdx++];
                }
                else
                    arr[idx++] = left[lIdx++];
            }
            else {
                if (lBits == rBits) {
                    if (left[lIdx] < right[rIdx])
                        arr[idx++] = left[lIdx++];
                    else
                        arr[idx++] = right[rIdx++];
                }
                else
                    arr[idx++] = right[rIdx++];
            }
        }
    }
    void mergeSort(vector<int>& arr) {
        if (arr.size() <= 1) return;
        int mid = arr.size() / 2;

        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());
        
        mergeSort(left);
        mergeSort(right);

        merge(arr, left, right);
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        for (auto& i : arr) mp[i] = setBits(i);
        mergeSort(arr);

        return arr;
    }
};