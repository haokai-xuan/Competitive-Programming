class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        def get_axis_dist(dir_cnt, opp_dir_cnt, t):
            return abs(dir_cnt - opp_dir_cnt) + t * 2

        ans = 0
        north = south = east = west = 0
        for c in s:
            if c == 'N':
                north += 1
            elif c == 'S':
                south += 1
            elif c == 'E':
                east += 1
            elif c == 'W':
                west += 1

            t1 = min(north, south, k)
            t2 = min(east, west, k - t1)

            ans = max(ans, get_axis_dist(north, south, t1) + get_axis_dist(east, west, t2))

        return ans