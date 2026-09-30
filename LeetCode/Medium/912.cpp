class Solution {
public:
    void merge(vector<int>& v, vector<int>& src1, vector<int>& src2) {
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < src1.size() || j < src2.size()) {
            if (i >= src1.size() || (j < src2.size() && src2[j] < src1[i])) {
                v[k] = src2[j];
                ++j;
            }
            else {
                v[k] = src1[i];
                ++i;
            }
            ++k;
        }
    }
    void mergeSort(vector<int>& v) {
        if (v.size() == 1)
            return;
        int lsize = v.size() / 2;
        int rsize = v.size() - lsize;
        vector<int> lv(lsize);
        vector<int> rv(rsize);
        for (int i = 0; i < lsize; i++)
            lv[i] = v[i];
        for (int i = 0; i < rsize; i++)
            rv[i] = v[lsize + i];

        mergeSort(lv);
        mergeSort(rv);
        merge(v, lv, rv);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums;
    }
};