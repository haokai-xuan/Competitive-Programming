class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        cols = len(matrix[0])
        seen_rows = set()
        seen_cols = set()
        candidates = []

        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    candidates.append((i, j))

        while candidates:
            r, c = candidates.pop()
            if r not in seen_rows:
                seen_rows.add(r)
                for i in range(cols):
                    matrix[r][i] = 0
            if c not in seen_cols:
                seen_cols.add(c)
                for i in range(rows):
                    matrix[i][c] = 0
