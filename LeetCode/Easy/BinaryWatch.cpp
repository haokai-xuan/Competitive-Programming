class Solution {
    vector<int> hourLED = {8, 4, 2, 1};
    vector<int> minuteLED = {32, 16, 8, 4, 2, 1};
    void solve(int index, int turnedOn, int hour, int minute, vector<string>& ans) {
        if (turnedOn == 0) {
            if (hour < 12 && minute < 60) {
                string h = to_string(hour);
                string m = minute < 10 ? "0" + to_string(minute) : to_string(minute);
                ans.push_back(h + ":" + m);
            }
            return;
        }

        if (index >= 10) return;

        if (index < 4)
            solve(index + 1, turnedOn - 1, hour + hourLED[index], minute, ans);
        else
            solve(index + 1, turnedOn - 1, hour, minute + minuteLED[index - 4], ans);

        solve(index + 1, turnedOn, hour, minute, ans);
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        solve(0, turnedOn, 0, 0, ans);
        return ans;
    }
};