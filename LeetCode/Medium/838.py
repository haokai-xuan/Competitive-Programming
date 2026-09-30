class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        N = len(dominoes)
        chars = list(dominoes)
        for i in range(N):
            if chars[i] == '.':
                left = i - 1
                right = i
                while right < N and chars[right] == '.':
                    right += 1
                
                if left < 0 and right >= N:
                    return dominoes
                elif left < 0:
                    if chars[right] == 'L':
                        chars[left + 1:right] = ['L'] * (right - (left + 1))
                elif right >= N:
                    if chars[left] == 'R':
                        chars[left + 1:right] = ['R'] * (right - (left + 1))
                elif chars[left] == 'L' and chars[right] == 'L':
                    chars[left + 1:right] = ['L'] * (right - (left + 1))
                elif chars[left] == 'R' and chars[right] == 'R':
                    chars[left + 1:right] = ['R'] * (right - (left + 1))
                elif chars[left] == 'R' and chars[right] == 'L':
                    while left < right:
                        chars[left] = 'R'
                        chars[right] = 'L'
                        left += 1
                        right -= 1
                i = right + 1

        return ''.join(chars)