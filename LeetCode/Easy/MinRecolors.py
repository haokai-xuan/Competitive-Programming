class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        length = len(blocks) - k + 1
        windows = [0] * length
        ans = float('inf')
        for i in range(length):
            if i >= 1 and windows[i - 1]:
                if blocks[i - 1] == 'W' and blocks[i + k - 1] == 'B':
                    windows[i] = windows[i - 1] - 1
                elif blocks[i - 1] == 'B' and blocks[i + k - 1] == 'W':
                    windows[i] = windows[i - 1] + 1
                else:
                    windows[i] = windows[i - 1]
            else:
                for j in range(i, k):
                    if blocks[j] == 'W':
                        windows[i] += 1

            ans = min(ans, windows[i])
        
        return ans
