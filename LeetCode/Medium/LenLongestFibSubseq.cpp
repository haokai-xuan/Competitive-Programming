class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> seq;
        int len = arr.size();
        int last = arr[len - 1];

        for (int i = 0; i < len; i++) {
            seq.insert(arr[i]);
        }
        
        int first, second;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            first = arr[i];
            for (int j = i + 1; j < len; j++) {
                int curr = 0;
                second = arr[j];
                int first_temp = first;
                while (first_temp + second <= last) {
                    if (seq.find(first_temp + second) != seq.end()) {
                        int first_temp_temp = first_temp;
                        first_temp = second;
                        second = first_temp_temp + second;
                        curr++;
                    }
                    else
                        break;
                }
                ans = max(curr, ans);
            }
        }

        return (ans ? ans + 2 : 0);
    }
};