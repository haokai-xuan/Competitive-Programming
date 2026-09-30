class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        return self.solve(n, 0, int(n ** (1/3)))

    def solve(self, target, sum, exp):
        if sum == target:
            return True

        for i in range(exp, -1, -1):
            print(i)
            term = 3 ** i
            if sum + term > target:
                continue
            if self.solve(target, sum + term, i - 1):
                return True

        return False