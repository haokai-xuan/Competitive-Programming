class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int required = tickets[k];
        int time = required;
        for (int i = 0; i < k; i++) {
            time += min(required, tickets[i]);
        }
        for (int i = k + 1; i < tickets.size(); i++) {
            if (tickets[i] < required) time += tickets[i];
            else {
                time += required - 1;
            }
        }
        return time;
    }
};