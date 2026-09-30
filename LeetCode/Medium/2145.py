class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        rel_seq = [0]
        for i in range(1, len(differences) + 1):
            rel_seq.append(rel_seq[i - 1] + differences[i - 1])

        min_index = -1
        min_index = -1
        min_val = min(rel_seq)
        max_val = max(rel_seq)
        for i in range(len(rel_seq)):
            if rel_seq[i] == min_val:
                min_index = i
            if rel_seq[i] == max_val:
                max_index = i

        diff = lower - min_val
        rel_seq = [i + diff for i in rel_seq]

        if rel_seq[max_index] > upper:
            return 0

        return upper - rel_seq[max_index] + 1