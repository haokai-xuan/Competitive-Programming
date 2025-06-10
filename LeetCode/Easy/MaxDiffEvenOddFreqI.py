class Solution:
    def maxDifference(self, s: str) -> int:
        freq = defaultdict(int)
        for c in s:
            freq[c] += 1

        odds = []
        evens = []
        for c, f in freq.items():
            if f % 2:
                odds.append(f)
            else:
                evens.append(f)

        return max(odds) - min(evens)