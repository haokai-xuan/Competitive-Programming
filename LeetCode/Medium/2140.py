class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        N = len(questions)
        dp = [0] * N
        dp[N - 1] = questions[N - 1][0]

        for i in range(N - 2, -1, -1):
            points = questions[i][0]
            brainpower = questions[i][1]
            next_index = i + questions[i][1] + 1

            if next_index < N:
                dp[i] = max(dp[i + 1], points + dp[next_index])
            else:
                dp[i] = max(points, dp[i + 1])

        return dp[0]
