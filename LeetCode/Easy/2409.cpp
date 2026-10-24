class Solution {
    vector<int> monthDays;

    int dayNumber(string& date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3));
        
        int ans = 0;
        for (int i = 0; i < month - 1; i++) ans += monthDays[i];
        ans += day;

        return ans;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return max(min(dayNumber(leaveBob), dayNumber(leaveAlice)) - max(dayNumber(arriveBob), dayNumber(arriveAlice)) + 1, 0);
    }
};