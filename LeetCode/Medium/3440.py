class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        top_gap = (-1, -1)
        top_gap2 = (-1, -1)
        top_gap3 = (-1, -1)
        startTime.append(eventTime)
        endTime.append(eventTime)
        num_meetings = len(startTime)
        for i in range(num_meetings):
            if startTime[i] == 0:
                continue

            if i > 0:
                dur = startTime[i] - endTime[i - 1]
            else:
                dur = startTime[i]

            if dur > top_gap3[0]:
                if dur > top_gap2[0]:
                    if dur > top_gap[0]:
                        top_gap3 = top_gap2
                        top_gap2 = top_gap
                        top_gap = (dur, i)
                    else:
                        top_gap3 = top_gap2
                        top_gap2 = (dur, i)
                else:
                    top_gap3 = (dur, i)

        ans = 0
        for i in range(num_meetings - 1):
            meeting_dur = endTime[i] - startTime[i]
            start = 0 if i == 0 else endTime[i - 1]
            end = startTime[i + 1]
            if top_gap3[0] >= meeting_dur:
                ans = max(ans, end - start)
            elif top_gap2[0] >= meeting_dur:
                if (top_gap[1] == i and top_gap2[1] == i + 1) or (top_gap[1] == i + 1 and top_gap2[1] == i):
                    ans = max(ans, startTime[i] - start + end - endTime[i])
                else:
                    ans = max(ans, end - start)
            elif top_gap[0] >= meeting_dur:
                if top_gap[1] == i or top_gap[1] == i + 1:
                    ans = max(ans, startTime[i] - start + end - endTime[i])
                else:
                    ans = max(ans, end - start)
            else:
                ans = max(ans, startTime[i] - start + end - endTime[i])

        return ans