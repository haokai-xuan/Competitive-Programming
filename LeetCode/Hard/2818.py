class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        N = len(nums)
        MOD = 10 ** 9 + 7
        ans = 1

        prime_scores = []
        for num in nums:
            score = 0

            for i in range(2, int(sqrt(num)) + 1):
                if num % i == 0:
                    score += 1
                    
                    while num % i == 0:
                        num /= i
            if num >= 2:
                score += 1
            prime_scores.append(score)

        left_bound = [-1] * N
        right_bound = [N] * N

        stack = []
        for i, s in enumerate(prime_scores):
            while stack and prime_scores[stack[-1]] < s:
                index = stack.pop()
                right_bound[index] = i
            if stack:
                left_bound[i] = stack[-1]

            stack.append(i)

        max_heap = [(-num, i) for i, num in enumerate(nums)]
        heapify(max_heap)

        while k > 0:
            num, index = heappop(max_heap)
            num = -num
            score = prime_scores[index]

            left_count = index - left_bound[index]
            right_count = right_bound[index] - index

            count = left_count * right_count
            operations = min(count, k)

            ans = (ans * pow(num, operations, MOD)) % MOD
            k -= operations

        return ans
