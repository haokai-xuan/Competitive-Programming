class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(apple.begin(), apple.end());
        sort(capacity.begin(), capacity.end());
        int ai = apple.size() - 1, ci = capacity.size() - 1;
        int ans = 0;
        while (ai >= 0) {
            if (capacity[ci] == 0) ci--;
            int m = min(apple[ai], capacity[ci]);
            apple[ai] -= m;
            capacity[ci] -= m;
            if (apple[ai] == 0) ai--;
        }
        return capacity.size() - ci;
    }
};