class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        ans = []
        start = 0
        for i in range(len(s) // k):
            temp = s[i * k:i * k + k]
            ans.append(temp)
            start = i * k

        if len(s) % k:
            if ans:
                start += k
            new_len = k * (1 + len(s) // k)
            print(new_len)
            ans.append(s[start:] + fill * (new_len - len(s)))

        return ans

        