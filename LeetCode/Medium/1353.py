class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()
        min_heap = []
        max_day = max(event[1] for event in events)
        ans = 0
        j = 0

        for i in range(1, max_day + 1):
            while j < len(events) and events[j][0] <= i:
                heappush(min_heap, events[j][1])
                j += 1
            while min_heap and min_heap[0] < i:
                heappop(min_heap)

            if min_heap:
                heappop(min_heap)
                ans += 1

        return ans