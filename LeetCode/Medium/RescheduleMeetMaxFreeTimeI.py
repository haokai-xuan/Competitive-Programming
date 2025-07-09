class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        num_meetings = len(startTime)
        ans = 0
        meet_dur = 0

        for i in range(num_meetings):
            meet_dur += endTime[i] - startTime[i]

            if i >= k - 1:
                if i - k >= 0:
                    left = endTime[i - k]
                else:
                    left = 0

                if i + 1 < num_meetings:
                    right = startTime[i + 1]
                else:
                    right = eventTime

                ans = max(ans, right - left - meet_dur)
                meet_dur -= endTime[i - k + 1] - startTime[i - k + 1]

        return ans
