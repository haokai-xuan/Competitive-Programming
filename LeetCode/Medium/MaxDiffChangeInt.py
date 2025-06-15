class Solution:
    def maxDiff(self, num: int) -> int:
        def change(num, is_min):
            s = str(num)
            first = s[0]
            digit = None

            if is_min:
                if first != "1":
                    digit = first
                else:
                    for c in s:
                        if c != first and c != "0":
                            digit = c
                            break
            else:
                for c in s:
                    if c != "9":
                        digit = c
                        break

            if not digit:
                return num

            ans = 0
            for c in s:
                ans *= 10
                if c == digit:
                    if is_min:
                        ans += 1 if digit == first else 0
                    else:
                        ans += 9
                else:
                    ans += int(c)

            return ans


        a = change(num, False)
        b = change(num, True)

        return a - b

        