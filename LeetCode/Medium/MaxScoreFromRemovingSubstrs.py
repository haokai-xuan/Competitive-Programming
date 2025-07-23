class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        stack = []
        substr = "ab" if x > y else "ba"
        score = 0
        for c in s:
            stack.append(c)
            if len(stack) >= 2:
                if ''.join([stack[-2], c]) == substr:
                    stack.pop()
                    stack.pop()
                    score += max(x, y)
        
        stack2 = []
        for c in stack:
            stack2.append(c)
            if len(stack2) > 1:
                if ''.join([stack2[-2], c]) == substr[::-1]:
                    stack2.pop()
                    stack2.pop()
                    score += min(x, y)

        return score        