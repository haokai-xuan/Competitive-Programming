class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        primes = self.sieve(left, right)
        # for i in primes:
        #     print(i)

        num1 = -1
        num2 = -1
        curr_min = 1e6

        for i in range(len(primes) - 1):
            if primes[i + 1] - primes[i] < curr_min:
                num1 = primes[i]
                num2 = primes[i + 1]
                curr_min = num2 - num1

        return [num1, num2]
        
    def sieve(self, left, right):
        num = 2
        primes = [True] * (right + 1)
        primes[1] = False
        result = []
        
        while num * num <= right:
            if primes[num]:
                for i in range(num * num, right + 1, num):
                    primes[i] = False

            num += 1
        
        for i in range(left, right + 1):
            if primes[i]:
                result.append(i)
        return result