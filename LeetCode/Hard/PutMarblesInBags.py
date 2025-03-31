class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        N = len(weights)

        pair_weights = []

        for i in range(N - 1):
            pair_weights.append(weights[i] + weights[i + 1])

        pair_weights.sort()

        max_score = weights[0] + weights[N - 1]
        min_score = weights[0] + weights[N - 1]

        for i in range(k - 1):
            min_score += pair_weights[i]

        for i in range(N - 2, N - 2 - k + 1, -1):
            max_score += pair_weights[i]

        return max_score - min_score