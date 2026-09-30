class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        mp = defaultdict(str)

        for i in range(len(s)):
            if s[i] in mp:
                mp[s[i]][1] = i
            else:
                mp[s[i]] = [i, i]

        ans = []

        intervals = list(mp.values())
        start = intervals[0][0]
        end = intervals[0][1]

        for current_start, current_end in intervals:
            if current_start <= end:
                end = max(end, current_end)
            else:
                ans.append(end - start + 1)
                start = current_start
                end = current_end

        ans.append(end - start + 1)

        return ans