class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort()

        prev_end = 0

        for start, end in meetings:
            start = max(start, prev_end + 1)
            length = end - start + 1

            if length < 0:
                length = 0

            days -= length

            prev_end = max(prev_end, end)


        return days