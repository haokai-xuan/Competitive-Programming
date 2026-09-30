class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        length = len(colors)
        
        ans = 0
        left = 0
        right = 1
        full_size = False

        while right < length + k - 1:
            if colors[right % length] == colors[(right - 1) % length]:
                left = right
                right = right + 1
                continue
            if right - left < k - 1:
                right += 1
            elif right - left == k - 1:
                ans += 1
                right += 1
                left += 1

        return ans