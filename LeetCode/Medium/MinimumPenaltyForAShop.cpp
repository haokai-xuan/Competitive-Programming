class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix_sum(n + 1, 0);
        vector<int> suffix_sum(n + 1, 0);
        int y_cnt = 0;
        int n_cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (i < n && customers[i] == 'N') n_cnt++;
            prefix_sum[i] = n_cnt;
        }
        for (int i = n; i >= 0; i--) {
            if (i < n && customers[i] == 'Y') y_cnt++;
            suffix_sum[i] = y_cnt;
        }
        int min_pen = INT_MAX;
        int index = -1;
        for (int i = 0; i <= n; i++) {
            int pen = suffix_sum[i];
            if (i > 0) pen += prefix_sum[i - 1];
            if (pen < min_pen) {
                min_pen = pen;
                index = i;
            }
        }
        return index;
    }
};